{
 "cells": [
  {
   "cell_type": "markdown",
   "id": "b82df19e-a20b-4db6-b61b-e88558335cf6",
   "metadata": {},
   "source": [
    "# **DS3040 Introduction to Deep Learning**"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "1fd48b40-e5ad-41da-81c0-d1c632581155",
   "metadata": {},
   "source": [
    "## **1. Develop a next-word predictor using different recurrent neural network architectures**\n",
    "\n",
    "### a) Load the shakespeare-hamlet.txt from the Gutenberg corpus of NLTK and perform necessary preprocessing\n",
    "### b) Tokenize the text, create word sequences, apply padding, and generate input sequence next word pairs for training.\n",
    "### c) Construct and train a language model using RNN and LSTM architectures\n",
    "### d) Describe the effectiveness of each model (RNN, LSTM) in performing the next word prediction task, comparing their performance"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 26,
   "id": "8b4d94dd-91cc-479c-b240-b0053b137e16",
   "metadata": {},
   "outputs": [],
   "source": [
    "import string\n",
    "from collections import Counter\n",
    "import torch\n",
    "import torch.nn as nn\n",
    "from torch.utils.data import Dataset, DataLoader\n",
    "from tensorflow.keras.preprocessing.text import Tokenizer\n",
    "import torch.optim as optim\n",
    "import nltk\n",
    "from nltk.corpus import stopwords"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "id": "3f34a3a2-a863-45a9-9520-6c03c45b36ef",
   "metadata": {},
   "outputs": [],
   "source": [
    "import numpy as np\n",
    "import matplotlib.pyplot as plt\n",
    "from tensorflow.keras.preprocessing.sequence import pad_sequences\n",
    "from sklearn.model_selection import train_test_split\n",
    "from tensorflow.keras.models import Sequential\n",
    "from tensorflow.keras.layers import Embedding, SimpleRNN, LSTM, GRU, Dense, Dropout\n",
    "from tensorflow.keras.callbacks import EarlyStopping"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "id": "885de37f-f131-4b8c-b71a-6981c0831278",
   "metadata": {},
   "outputs": [],
   "source": [
    "def preprocess_text(text):\n",
    "    text = str(text).lower()\n",
    "    text = text.translate(str.maketrans('','', string.punctuation))\n",
    "    words = [w for w in text.split() if w not in stop_words]\n",
    "    return words"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "id": "50d2d5ca-a2bd-4156-a433-2c2ae22f6aa9",
   "metadata": {},
   "outputs": [],
   "source": [
    "def train_and_evaluate(model,train_loader, criterion, optimizer, epochs = 5):\n",
    "    model.train()\n",
    "    loss_history = []\n",
    "\n",
    "    for epoch in range(epochs):\n",
    "        total_loss = 0\n",
    "        for inputs, targets in train_loader:\n",
    "            optimizer.zero_grad()\n",
    "            outputs=model(inputs)\n",
    "            if outputs.shape!=targets.shape and len(targets.shape)==1:\n",
    "                outputs = outputs.squeeze()\n",
    "            loss = criterion(outputs, targets)\n",
    "            loss.backward()\n",
    "            optimizer.step()\n",
    "            total_loss+=loss.item()\n",
    "        avg_loss=total_loss/len(train_loader)\n",
    "        loss_history.append(avg_loss)\n",
    "        print(f\"Epoch {epoch+1}/{epochs}, Loss: {avg_loss:.4f}\")\n",
    "    return loss_history"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "id": "b00b9f71-ceeb-4f19-9bff-a65f0ee369a2",
   "metadata": {},
   "outputs": [],
   "source": [
    "def plot_losses(losses_dict, title):\n",
    "    plt.figure(figsize=(10,6))\n",
    "    for model_name, losses in losses_dict.items():\n",
    "        plt.plot(losses, label=model_name, marker='o')\n",
    "    plt.title(title)\n",
    "    plt.xlabel('Epochs')\n",
    "    plt.ylabel('Loss')\n",
    "    plt.legend()\n",
    "    plt.grid(True)\n",
    "    plt.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "id": "c343f3ff-5663-4804-9699-8a81f6e87dc7",
   "metadata": {},
   "outputs": [],
   "source": [
    "with open ('/home/142301026/Downloads/Deep_Learning/Lab5/data/shakespeare-hamlet.txt', 'r') as f:\n",
    "    content = f.read()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 28,
   "id": "c42e94d9-d330-46dc-b928-b5f569f1a740",
   "metadata": {},
   "outputs": [],
   "source": [
    "# hamlet_tokens = preprocess_text(content)\n",
    "\"\"\"\n",
    "with open ('/home/142301026/Downloads/Deep_Learning/Lab5/nltk_data/nltk_data/corpora/stopwords/english') as f:\n",
    "    stopwords = f.read()\n",
    "\"\"\"\n",
    "stop_words = set(stopwords.words('english'))\n",
    "hamlet_text = content\n",
    "hamlet_tokens = preprocess_text(hamlet_text)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 31,
   "id": "796ddb6c-e7f6-496a-886b-804d5c6e9e18",
   "metadata": {},
   "outputs": [],
   "source": [
    "hamlet_vocab = {word: i for i, (word,count) in enumerate(Counter(hamlet_tokens).items())}\n",
    "vocab_size_lm = len(hamlet_vocab)\n",
    "hamlet_seq = [hamlet_vocab[word] for word in hamlet_tokens]"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 32,
   "id": "7410425d-b290-4ade-8847-799b2b52a51a",
   "metadata": {},
   "outputs": [],
   "source": [
    "seq_length = 50\n",
    "inputs_lm, targets_lm = [],[]"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 33,
   "id": "2634f21b-2ba9-4272-9272-66fee96f9cf7",
   "metadata": {},
   "outputs": [],
   "source": [
    "for i in range(len(hamlet_seq)-seq_length):\n",
    "    inputs_lm.append(hamlet_seq[i:i+seq_length])\n",
    "    targets_lm.append(hamlet_seq[i+seq_length])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 34,
   "id": "a5f4e30f-7450-48ad-98a2-3bb0145f9278",
   "metadata": {},
   "outputs": [],
   "source": [
    "X_lm = torch.tensor(inputs_lm, dtype = torch.long)\n",
    "y_lm = torch.tensor(targets_lm, dtype = torch.long)\n",
    "\n",
    "lm_dataset = torch.utils.data.TensorDataset(X_lm, y_lm)\n",
    "lm_loader = DataLoader(lm_dataset, batch_size = 128, shuffle = True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 35,
   "id": "37a7ff8a-32ec-4ced-816b-5472cd11578d",
   "metadata": {},
   "outputs": [],
   "source": [
    "class NextWordModel(nn.Module):\n",
    "    def __init__(self, rnn_type, vocab_size, embed_dim, hidden_dim):\n",
    "        super(NextWordModel, self).__init__()\n",
    "        self.embedding = nn.Embedding(vocab_size, embed_dim)\n",
    "        if rnn_type == 'RNN':\n",
    "            self.rnn =  nn.RNN(embed_dim, hidden_dim, batch_first = True)\n",
    "        if rnn_type == 'LSTM':\n",
    "            self.rnn =  nn.LSTM(embed_dim, hidden_dim, batch_first = True)\n",
    "        self.fc = nn.Linear(hidden_dim, vocab_size)\n",
    "\n",
    "    def forward(self,x):\n",
    "        embedded = self.embedding(x)\n",
    "        output, hidden = self.rnn(embedded)\n",
    "\n",
    "        if isinstance(hidden, tuple):\n",
    "            hidden = hidden[0]\n",
    "\n",
    "        final_hidden = hidden[-1]\n",
    "        return self.fc(final_hidden)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 36,
   "id": "bb668c2b-35e8-4ad6-80cc-8cadd1e2e2cd",
   "metadata": {},
   "outputs": [],
   "source": [
    "lm_embed_dim = 64\n",
    "lm_hidden_dim = 128\n",
    "criterion_lm = nn.CrossEntropyLoss()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 37,
   "id": "95b20a90-0e91-4a5a-bfbf-3a48e9459a48",
   "metadata": {},
   "outputs": [],
   "source": [
    "models_lm = {\n",
    "    'RNN': NextWordModel('RNN', vocab_size_lm, lm_embed_dim, lm_hidden_dim),\n",
    "    'LSTM': NextWordModel('LSTM', vocab_size_lm, lm_embed_dim, lm_hidden_dim)\n",
    "}\n",
    "\n",
    "lm_loss_results = {}"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 38,
   "id": "ea1ab466-2ca9-40f6-a3a7-5b26f690b735",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Training RNN for Next Word Prediction\n",
      "Epoch 1/5, Loss: 7.9661\n",
      "Epoch 2/5, Loss: 6.6834\n",
      "Epoch 3/5, Loss: 5.0881\n",
      "Epoch 4/5, Loss: 3.5177\n",
      "Epoch 5/5, Loss: 2.4755\n",
      "Training LSTM for Next Word Prediction\n",
      "Epoch 1/5, Loss: 7.8235\n",
      "Epoch 2/5, Loss: 6.9736\n",
      "Epoch 3/5, Loss: 5.6344\n",
      "Epoch 4/5, Loss: 3.9876\n",
      "Epoch 5/5, Loss: 2.6733\n"
     ]
    }
   ],
   "source": [
    "for name, model in models_lm.items():\n",
    "    print(f\"Training {name} for Next Word Prediction\")\n",
    "    optimizer = optim.Adam(model.parameters(), lr=0.005)\n",
    "    lm_loss_results[name] = train_and_evaluate(model,lm_loader,criterion_lm, optimizer, epochs=5)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 39,
   "id": "bcae8134-cc61-47dd-a24a-6cd789f7fcba",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "image/png": "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tUKzXH8G6Do1QSIiIiIi+ZRhGDSuWJTGFYuy92QCU1Yf4ofYP9j8+3k2/76V8kUL8FyT8nSvWxpPt2w2MDYXzLJN+GNXArXKNskzDRDocjgREREREadQpYQv7z9aizWvRTCgxQP4erpy6EwSbyzYSfiYSMYt+42zl1Ksjpkj1ASJiIiIiDiRAF9PXmtfhfUjWzGqcwilC3txLukqH6/YR/iYSF6fH8eB05esjulQaoJERERERJxQAQ9XnmlcnqiXWzD+yTrUKu1HyrV0Zm48QusPV9H3qy1s/v0cpmlaHfW+00yQiIiIiIgTc3Wx8WDNknSqEcimQ+eYvPogy/fEs2z3KZbtPkWtoEL0a1qBdtUCcHX57zmUtHSTjYfOsfWMQZFD5wirWByXu7nJggXUBImIiIiICIZh0LBCERpWKML++EtMXXOIeTHH2H70AgNnxhDk78VzjcvzaL0gVu87zds/7ubExWTAha/2bSHQz5NRnUNoXz3wL9/LarocTkREREREMqlYvCCjH6nBuhERDGlVicLebhw9d4W3ftxN/X8vp/+MmIwG6L9OXkxmwIwYluw8YVHqrFMTJCIiIiIit1S0oAfD21Rm3YhWvNO1OmX9vbh8Ne2Wa69PDr39427S0nP3HJGaIBERERERuSMvdxd6NSrL/z1S847rTODExWQ2HTqXM8HukpogERERERHJkjNZfI5QfGLyXy+ykJogERERERHJkuI+nvd1nVXUBImIiIiISJY0KO9PoJ8nt7sRtgEE+nnSoLx/TsbKNjVBIiIiIiKSJS42g1GdQwBuaoSufz+qc0iuf16QmiAREREREcmy9tUDmfhUKCX8Ml/yVsLPk4lPheaJ5wTpYakiIiIiIpIt7asH0iakBOv3x/PL6o20bdqQsIrFc/0ZoOvUBImIiIiISLa52Awalvfn7B6ThuX980wDBLocTkREREREnIyaIBERERERcSpqgkRERERExKmoCRIREREREaeiJkhERERERJyKmiAREREREXEqaoJERERERMSpqAkSERERERGnoiZIREREREScipogERERERFxKmqCRERERETEqagJEhERERERp6ImSEREREREnIqr1QHuhWmaACQkJFicBFJTU7l8+TIJCQm4ublZHSffUX0dTzV2LNXXsVRfx1J9HUv1dSzV17FyU32v9wTXe4Q7ydNNUGJiIgBBQUEWJxERERERkdwgMTERPz+/O64xzKy0SrlUeno6x48fx8fHB8MwLM2SkJBAUFAQR48exdfX19Is+ZHq63iqsWOpvo6l+jqW6utYqq9jqb6OlZvqa5omiYmJlCxZEpvtzlM/efpMkM1mo3Tp0lbHyMTX19fyDZCfqb6Opxo7lurrWKqvY6m+jqX6Opbq61i5pb5/dQboOt0YQUREREREnIqaIBERERERcSpqgu4TDw8PRo0ahYeHh9VR8iXV1/FUY8dSfR1L9XUs1dexVF/HUn0dK6/WN0/fGEFERERERCS7dCZIREREREScipogERERERFxKmqCRERERETEqagJEhERERERp6ImKBsmTJhAuXLl8PT0pGHDhmzatOmO6+fMmUOVKlXw9PSkRo0aLFq0KIeS5k3Zqe/06dMxDCPTl6enZw6mzVuio6Pp3LkzJUuWxDAMFixY8JeviYqKIjQ0FA8PDypWrMj06dMdnjOvym59o6Kibtq/hmFw8uTJnAmcx4wePZr69evj4+ND8eLF6dq1K7/++utfvk6fwVlzN/XVZ3DWTZw4kZo1a954kGRYWBiLFy++42u0d7Muu/XV3r03Y8aMwTAMhg0bdsd1eWEPqwnKom+//Zbhw4czatQoYmJiqFWrFu3atSM+Pv6W69etW8cTTzzBc889x7Zt2+jatStdu3Zl586dOZw8b8hufcH+ZOITJ07c+Dp8+HAOJs5bkpKSqFWrFhMmTMjS+kOHDtGpUydatmxJbGwsw4YN4/nnn2fp0qUOTpo3Zbe+1/3666+Z9nDx4sUdlDBvW7VqFQMHDmTDhg0sW7aM1NRU2rZtS1JS0m1fo8/grLub+oI+g7OqdOnSjBkzhq1bt7JlyxYiIiLo0qULu3btuuV67d3syW59QXv3bm3evJlJkyZRs2bNO67LM3vYlCxp0KCBOXDgwBvfp6WlmSVLljRHjx59y/WPPfaY2alTp0zHGjZsaL7wwgsOzZlXZbe+06ZNM/38/HIoXf4CmPPnz7/jmldffdWsVq1apmOPP/642a5dOwcmyx+yUt+VK1eagHn+/PkcyZTfxMfHm4C5atWq267RZ/Ddy0p99Rl8bwoXLmxOmTLllj/T3r13d6qv9u7dSUxMNCtVqmQuW7bMbN68uTl06NDbrs0re1hngrLg6tWrbN26ldatW984ZrPZaN26NevXr7/la9avX59pPUC7du1uu96Z3U19AS5dukTZsmUJCgr6y//1kezR/s0ZtWvXJjAwkDZt2rB27Vqr4+QZFy9eBMDf3/+2a7SH715W6gv6DL4baWlpzJ49m6SkJMLCwm65Rnv37mWlvqC9ezcGDhxIp06dbtqbt5JX9rCaoCw4c+YMaWlpBAQEZDoeEBBw22v4T548ma31zuxu6hscHMyXX37JDz/8wIwZM0hPTyc8PJxjx47lROR873b7NyEhgStXrliUKv8IDAzk888/Z968ecybN4+goCBatGhBTEyM1dFyvfT0dIYNG0bjxo2pXr36bdfpM/juZLW++gzOnri4OAoWLIiHhwf9+/dn/vz5hISE3HKt9m72Zae+2rvZN3v2bGJiYhg9enSW1ueVPexqdQCRuxEWFpbpf3nCw8OpWrUqkyZN4p133rEwmchfCw4OJjg4+Mb34eHhHDhwgHHjxvH1119bmCz3GzhwIDt37mTNmjVWR8mXslpffQZnT3BwMLGxsVy8eJG5c+fSp08fVq1addt/qEv2ZKe+2rvZc/ToUYYOHcqyZcvy3Q0k1ARlQdGiRXFxceHUqVOZjp86dYoSJUrc8jUlSpTI1npndjf1/TM3Nzfq1KnD/v37HRHR6dxu//r6+uLl5WVRqvytQYMG+of9Xxg0aBA//fQT0dHRlC5d+o5r9Rmcfdmp75/pM/jO3N3dqVixIgB169Zl8+bNfPzxx0yaNOmmtdq72Zed+v6Z9u6dbd26lfj4eEJDQ28cS0tLIzo6mvHjx5OSkoKLi0um1+SVPazL4bLA3d2dunXrsmLFihvH0tPTWbFixW2vOQ0LC8u0HmDZsmV3vEbVWd1Nff8sLS2NuLg4AgMDHRXTqWj/5rzY2Fjt39swTZNBgwYxf/58IiMjKV++/F++Rns46+6mvn+mz+DsSU9PJyUl5ZY/0969d3eq759p795Zq1atiIuLIzY29sZXvXr16NmzJ7GxsTc1QJCH9rDVd2bIK2bPnm16eHiY06dPN3fv3m3269fPLFSokHny5EnTNE2zV69e5ogRI26sX7t2renq6mq+//775p49e8xRo0aZbm5uZlxcnFW/Qq6W3fq+/fbb5tKlS80DBw6YW7duNXv06GF6enqau3btsupXyNUSExPNbdu2mdu2bTMB88MPPzS3bdtmHj582DRN0xwxYoTZq1evG+sPHjxoent7m6+88oq5Z88ec8KECaaLi4u5ZMkSq36FXC279R03bpy5YMECc9++fWZcXJw5dOhQ02azmcuXL7fqV8jVBgwYYPr5+ZlRUVHmiRMnbnxdvnz5xhp9Bt+9u6mvPoOzbsSIEeaqVavMQ4cOmTt27DBHjBhhGoZh/vLLL6Zpau/eq+zWV3v33v357nB5dQ+rCcqGTz/91CxTpozp7u5uNmjQwNywYcONnzVv3tzs06dPpvXfffedWblyZdPd3d2sVq2a+fPPP+dw4rwlO/UdNmzYjbUBAQFmx44dzZiYGAtS5w3Xb8n856/rNe3Tp4/ZvHnzm15Tu3Zt093d3axQoYI5bdq0HM+dV2S3vmPHjjUfeOAB09PT0/T39zdbtGhhRkZGWhM+D7hVbYFMe1KfwXfvbuqrz+Cse/bZZ82yZcua7u7uZrFixcxWrVrd+Ae6aWrv3qvs1ld79979uQnKq3vYME3TzLnzTiIiIiIiItbSTJCIiIiIiDgVNUEiIiIiIuJU1ASJiIiIiIhTURMkIiIiIiJORU2QiIiIiIg4FTVBIiIiIiLiVNQEiYiIiIiIU1ETJCIiIiIiTkVNkIiIOA3DMFiwYIHVMURExGJqgkREJEc8/fTTGIZx01f79u2tjiYiIk7G1eoAIiLiPNq3b8+0adMyHfPw8LAojYiIOCudCRIRkRzj4eFBiRIlMn0VLlwYsF+qNnHiRDp06ICXlxcVKlRg7ty5mV4fFxdHREQEXl5eFClShH79+nHp0qVMa7788kuqVauGh4cHgYGBDBo0KNPPz5w5w8MPP4y3tzeVKlVi4cKFN352/vx5evbsSbFixfDy8qJSpUo3NW0iIpL3qQkSEZFc4x//+AfdunVj+/bt9OzZkx49erBnzx4AkpKSaNeuHYULF2bz5s3MmTOH5cuXZ2pyJk6cyMCBA+nXrx9xcXEsXLiQihUrZnqPt99+m8cee4wdO3bQsWNHevbsyblz5268/+7du1m8eDF79uxh4sSJFC1aNOcKICIiOcIwTdO0OoSIiOR/Tz/9NDNmzMDT0zPT8ddff53XX38dwzDo378/EydOvPGzRo0aERoaymeffcbkyZN57bXXOHr0KAUKFABg0aJFdO7cmePHjxMQEECpUqV45pln+Ne//nXLDIZh8MYbb/DOO+8A9saqYMGCLF68mPbt2/PQQw9RtGhRvvzySwdVQUREcgPNBImISI5p2bJlpiYHwN/f/8afw8LCMv0sLCyM2NhYAPbs2UOtWrVuNEAAjRs3Jj09nV9//RXDMDh+/DitWrW6Y4aaNWve+HOBAgXw9fUlPj4egAEDBtCtWzdiYmJo27YtXbt2JTw8/K5+VxERyb3UBImISI4pUKDATZen3S9eXl5ZWufm5pbpe8MwSE9PB6BDhw4cPnyYRYsWsWzZMlq1asXAgQN5//3373teERGxjmaCREQk19iwYcNN31etWhWAqlWrsn37dpKSkm78fO3atdhsNoKDg/Hx8aFcuXKsWLHinjIUK1aMPn36MGPGDD766CO++OKLe/r7REQk99GZIBERyTEpKSmcPHky0zFXV9cbNx+YM2cO9erVo0mTJnzzzTds2rSJqVOnAtCzZ09GjRpFnz59eOuttzh9+jSDBw+mV69eBAQEAPDWW2/Rv39/ihcvTocOHUhMTGTt2rUMHjw4S/nefPNN6tatS7Vq1UhJSeGnn3660YSJiEj+oSZIRERyzJIlSwgMDMx0LDg4mL179wL2O7fNnj2bF198kcDAQGbNmkVISAgA3t7eLF26lKFDh1K/fn28vb3p1q0bH3744Y2/q0+fPiQnJzNu3DhefvllihYtSvfu3bOcz93dnZEjR/L777/j5eVF06ZNmT179n34zUVEJDfR3eFERCRXMAyD+fPn07VrV6ujiIhIPqeZIBERERERcSpqgkRERERExKloJkhERHIFXZ0tIiI5RWeCRERERETEqagJEhERERERp6ImSEREREREnIqaIBERERERcSpqgkRERERExKmoCRIREREREaeiJkhERERERJyKmiAREREREXEq/w+/9oou5+E3SAAAAABJRU5ErkJggg==",
      "text/plain": [
       "<Figure size 1000x600 with 1 Axes>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": [
    "plot_losses(lm_loss_results, \"Next Word Prediction Training Loss (RNN vs LSTM)\")"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "3cacddca-7f4f-4e5d-8c71-853c505b68cf",
   "metadata": {},
   "source": [
    "## **2. Develop a sentence classification system using recurrent neural networks**\n",
    "\n",
    "### a) Load a text classification dataset(IMDB Dataset.csv) and perform necessary preprocessing.\n",
    "### b) Convert the text into numerical sequences using tokenization and padding.\n",
    "### c) Construct and train a classification model using a Simple RNN architecture.\n",
    "### d) Replace the Simple RNN with an LSTM and train the model.\n",
    "### e) Compare the performance of RNN and LSTM models and justify which performs better. "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 40,
   "id": "2a67c109-5569-4e54-ab76-a82eb357141e",
   "metadata": {},
   "outputs": [],
   "source": [
    "import pandas as pd"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 41,
   "id": "dc0f2d54-a902-4e7f-a683-57831d65de9d",
   "metadata": {
    "scrolled": true
   },
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>review</th>\n",
       "      <th>sentiment</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>One of the other reviewers has mentioned that ...</td>\n",
       "      <td>positive</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>A wonderful little production. &lt;br /&gt;&lt;br /&gt;The...</td>\n",
       "      <td>positive</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>I thought this was a wonderful way to spend ti...</td>\n",
       "      <td>positive</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>Basically there's a family where a little boy ...</td>\n",
       "      <td>negative</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>Petter Mattei's \"Love in the Time of Money\" is...</td>\n",
       "      <td>positive</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>...</th>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49995</th>\n",
       "      <td>I thought this movie did a down right good job...</td>\n",
       "      <td>positive</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49996</th>\n",
       "      <td>Bad plot, bad dialogue, bad acting, idiotic di...</td>\n",
       "      <td>negative</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49997</th>\n",
       "      <td>I am a Catholic taught in parochial elementary...</td>\n",
       "      <td>negative</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49998</th>\n",
       "      <td>I'm going to have to disagree with the previou...</td>\n",
       "      <td>negative</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49999</th>\n",
       "      <td>No one expects the Star Trek movies to be high...</td>\n",
       "      <td>negative</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "<p>50000 rows × 2 columns</p>\n",
       "</div>"
      ],
      "text/plain": [
       "                                                  review sentiment\n",
       "0      One of the other reviewers has mentioned that ...  positive\n",
       "1      A wonderful little production. <br /><br />The...  positive\n",
       "2      I thought this was a wonderful way to spend ti...  positive\n",
       "3      Basically there's a family where a little boy ...  negative\n",
       "4      Petter Mattei's \"Love in the Time of Money\" is...  positive\n",
       "...                                                  ...       ...\n",
       "49995  I thought this movie did a down right good job...  positive\n",
       "49996  Bad plot, bad dialogue, bad acting, idiotic di...  negative\n",
       "49997  I am a Catholic taught in parochial elementary...  negative\n",
       "49998  I'm going to have to disagree with the previou...  negative\n",
       "49999  No one expects the Star Trek movies to be high...  negative\n",
       "\n",
       "[50000 rows x 2 columns]"
      ]
     },
     "execution_count": 41,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df = pd.read_csv('/home/142301026/Downloads/Deep_Learning/Lab5/data/IMDB Dataset.csv')\n",
    "df"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 42,
   "id": "21548b39-4c88-425b-8037-918f63c1ec37",
   "metadata": {
    "scrolled": true
   },
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>review</th>\n",
       "      <th>sentiment</th>\n",
       "      <th>clean_tokens</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>One of the other reviewers has mentioned that ...</td>\n",
       "      <td>positive</td>\n",
       "      <td>[one, reviewers, mentioned, watching, 1, oz, e...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>A wonderful little production. &lt;br /&gt;&lt;br /&gt;The...</td>\n",
       "      <td>positive</td>\n",
       "      <td>[wonderful, little, production, br, br, filmin...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>I thought this was a wonderful way to spend ti...</td>\n",
       "      <td>positive</td>\n",
       "      <td>[thought, wonderful, way, spend, time, hot, su...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>Basically there's a family where a little boy ...</td>\n",
       "      <td>negative</td>\n",
       "      <td>[basically, theres, family, little, boy, jake,...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>Petter Mattei's \"Love in the Time of Money\" is...</td>\n",
       "      <td>positive</td>\n",
       "      <td>[petter, matteis, love, time, money, visually,...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>...</th>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "      <td>...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49995</th>\n",
       "      <td>I thought this movie did a down right good job...</td>\n",
       "      <td>positive</td>\n",
       "      <td>[thought, movie, right, good, job, wasnt, crea...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49996</th>\n",
       "      <td>Bad plot, bad dialogue, bad acting, idiotic di...</td>\n",
       "      <td>negative</td>\n",
       "      <td>[bad, plot, bad, dialogue, bad, acting, idioti...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49997</th>\n",
       "      <td>I am a Catholic taught in parochial elementary...</td>\n",
       "      <td>negative</td>\n",
       "      <td>[catholic, taught, parochial, elementary, scho...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49998</th>\n",
       "      <td>I'm going to have to disagree with the previou...</td>\n",
       "      <td>negative</td>\n",
       "      <td>[im, going, disagree, previous, comment, side,...</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>49999</th>\n",
       "      <td>No one expects the Star Trek movies to be high...</td>\n",
       "      <td>negative</td>\n",
       "      <td>[one, expects, star, trek, movies, high, art, ...</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "<p>50000 rows × 3 columns</p>\n",
       "</div>"
      ],
      "text/plain": [
       "                                                  review sentiment  \\\n",
       "0      One of the other reviewers has mentioned that ...  positive   \n",
       "1      A wonderful little production. <br /><br />The...  positive   \n",
       "2      I thought this was a wonderful way to spend ti...  positive   \n",
       "3      Basically there's a family where a little boy ...  negative   \n",
       "4      Petter Mattei's \"Love in the Time of Money\" is...  positive   \n",
       "...                                                  ...       ...   \n",
       "49995  I thought this movie did a down right good job...  positive   \n",
       "49996  Bad plot, bad dialogue, bad acting, idiotic di...  negative   \n",
       "49997  I am a Catholic taught in parochial elementary...  negative   \n",
       "49998  I'm going to have to disagree with the previou...  negative   \n",
       "49999  No one expects the Star Trek movies to be high...  negative   \n",
       "\n",
       "                                            clean_tokens  \n",
       "0      [one, reviewers, mentioned, watching, 1, oz, e...  \n",
       "1      [wonderful, little, production, br, br, filmin...  \n",
       "2      [thought, wonderful, way, spend, time, hot, su...  \n",
       "3      [basically, theres, family, little, boy, jake,...  \n",
       "4      [petter, matteis, love, time, money, visually,...  \n",
       "...                                                  ...  \n",
       "49995  [thought, movie, right, good, job, wasnt, crea...  \n",
       "49996  [bad, plot, bad, dialogue, bad, acting, idioti...  \n",
       "49997  [catholic, taught, parochial, elementary, scho...  \n",
       "49998  [im, going, disagree, previous, comment, side,...  \n",
       "49999  [one, expects, star, trek, movies, high, art, ...  \n",
       "\n",
       "[50000 rows x 3 columns]"
      ]
     },
     "execution_count": 42,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df['clean_tokens'] = df['review'].apply(preprocess_text)\n",
    "df"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 43,
   "id": "30b2587e-d3cf-4f4e-829c-31524128a4ae",
   "metadata": {},
   "outputs": [],
   "source": [
    "word_counts = Counter(word for tokens in df['clean_tokens'] for word in tokens)\n",
    "vocab = {word:i+2 for i,(word,count) in enumerate(word_counts.items())}\n",
    "vocab_size_cls = len(vocab)+2"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 44,
   "id": "2d9731f9-ea09-4c30-811b-7a4161cffcae",
   "metadata": {},
   "outputs": [],
   "source": [
    "def text_to_seq(tokens):\n",
    "    return [vocab.get(word,1) for word in tokens]\n",
    "\n",
    "df['sequences'] = df['clean_tokens'].apply(text_to_seq)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 45,
   "id": "32aa0494-bcde-48d8-a887-c5475362e84f",
   "metadata": {},
   "outputs": [],
   "source": [
    "class ClassificationDataset(Dataset):\n",
    "    def __init__(self,sequences, labels):\n",
    "        self.sequences = [torch.tensor(seq) for seq in sequences]\n",
    "        self.labels = labels.values\n",
    "\n",
    "    def __len__(self):\n",
    "        return len(self.sequences)\n",
    "\n",
    "    def __getitem__(self,idx):\n",
    "        return self.sequences[idx], torch.tensor(self.labels[idx], dtype=torch.float32)\n",
    "\n",
    "def collate_fn_pad(batch):\n",
    "    sequences, labels = zip(*batch)\n",
    "    sequences_padded = pad_sequence(sequences, batch_first = True, padding_value = 0)\n",
    "    labels = torch.stack(labels)\n",
    "    return sequences_padded, labels\n",
    "\n",
    "train_data, test_data, train_labels, test_labels = train_test_split(df['sequences'], df['sentiment'], test_size=0.2, random_state = 42)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 46,
   "id": "7ff190f8-6b16-480c-9256-892345cd1168",
   "metadata": {},
   "outputs": [],
   "source": [
    "train_dataset = ClassificationDataset(train_data,train_labels)\n",
    "train_loader = DataLoader(train_dataset, batch_size=32, collate_fn=collate_fn_pad, shuffle = True)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 47,
   "id": "962c91c5-5c53-47a3-878a-b5df694b9e4c",
   "metadata": {},
   "outputs": [],
   "source": [
    "class TextClassificationModel(nn.Module):\n",
    "    def __init__(self,rnn_type,vocab_size, embed_dim, hidden_dim, output_dim):\n",
    "        super(TextClassificationModel,self).__init__()\n",
    "        self.embedding = nn.Embedding(vocab_size, embed_dim, padding_idx=0)\n",
    "\n",
    "        if rnn_type == 'RNN':\n",
    "            self.rnn = nn.RNN(embed_dim, hidden_dim, batch_first = True)\n",
    "        elif rnn_type == 'LSTM':\n",
    "            self.rnn = nn.LSTM(embed_dim, hidden_dim, batch_first = True)\n",
    "        self.fc = nn.Linear(hidden_dim,output_dim)\n",
    "\n",
    "    def forward(self,x):\n",
    "        embedded = self.embedding(x)\n",
    "        output,hidden=self.rnn(embedded)\n",
    "\n",
    "        if isinstance(hidden,tuple):\n",
    "            hidden=hidden[0]\n",
    "        final_hidden = hidden[0]\n",
    "        return self.fc(final_hidden)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 48,
   "id": "312c3230-58bb-482f-b556-e0958a71a021",
   "metadata": {},
   "outputs": [],
   "source": [
    "embed_dim = 64\n",
    "hidden_dim = 128\n",
    "output_dim = 1\n",
    "criterion_cls = nn.BCEWithLogitsLoss()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 49,
   "id": "46e5306a-4d44-456f-8df8-4a11f57dc648",
   "metadata": {},
   "outputs": [],
   "source": [
    "model_cls = {\n",
    "    'RNN' : TextClassificationModel('RNN', vocab_size_cls, embed_dim,hidden_dim,output_dim),\n",
    "    'LSTM' : TextClassificationModel('LSTM', vocab_size_cls, embed_dim,hidden_dim,output_dim)\n",
    "}"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 50,
   "id": "dcb68e11-6351-47c6-a936-9f33b0f25e49",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Training {name} for Text Classification\n"
     ]
    },
    {
     "ename": "TypeError",
     "evalue": "new(): invalid data type 'str'",
     "output_type": "error",
     "traceback": [
      "\u001b[0;31m---------------------------------------------------------------------------\u001b[0m",
      "\u001b[0;31mTypeError\u001b[0m                                 Traceback (most recent call last)",
      "Cell \u001b[0;32mIn[50], line 6\u001b[0m\n\u001b[1;32m      4\u001b[0m     \u001b[38;5;28mprint\u001b[39m(\u001b[38;5;124m\"\u001b[39m\u001b[38;5;124mTraining \u001b[39m\u001b[38;5;132;01m{name}\u001b[39;00m\u001b[38;5;124m for Text Classification\u001b[39m\u001b[38;5;124m\"\u001b[39m)\n\u001b[1;32m      5\u001b[0m     optimizer \u001b[38;5;241m=\u001b[39m optim\u001b[38;5;241m.\u001b[39mAdam(model\u001b[38;5;241m.\u001b[39mparameters(), lr\u001b[38;5;241m=\u001b[39m\u001b[38;5;241m0.001\u001b[39m)\n\u001b[0;32m----> 6\u001b[0m     cls_loss_results[name] \u001b[38;5;241m=\u001b[39m \u001b[43mtrain_and_evaluate\u001b[49m\u001b[43m(\u001b[49m\u001b[43mmodel\u001b[49m\u001b[43m,\u001b[49m\u001b[43m \u001b[49m\u001b[43mtrain_loader\u001b[49m\u001b[43m,\u001b[49m\u001b[43m \u001b[49m\u001b[43mcriterion_cls\u001b[49m\u001b[43m,\u001b[49m\u001b[43m \u001b[49m\u001b[43moptimizer\u001b[49m\u001b[43m,\u001b[49m\u001b[43m \u001b[49m\u001b[43mepochs\u001b[49m\u001b[38;5;241;43m=\u001b[39;49m\u001b[38;5;241;43m5\u001b[39;49m\u001b[43m)\u001b[49m\n\u001b[1;32m      8\u001b[0m plot_losses(cls_loss_results, \u001b[38;5;124m\"\u001b[39m\u001b[38;5;124mText Classification Training Loss (RNN vs LSTM)\u001b[39m\u001b[38;5;124m\"\u001b[39m)\n",
      "Cell \u001b[0;32mIn[4], line 7\u001b[0m, in \u001b[0;36mtrain_and_evaluate\u001b[0;34m(model, train_loader, criterion, optimizer, epochs)\u001b[0m\n\u001b[1;32m      5\u001b[0m \u001b[38;5;28;01mfor\u001b[39;00m epoch \u001b[38;5;129;01min\u001b[39;00m \u001b[38;5;28mrange\u001b[39m(epochs):\n\u001b[1;32m      6\u001b[0m     total_loss \u001b[38;5;241m=\u001b[39m \u001b[38;5;241m0\u001b[39m\n\u001b[0;32m----> 7\u001b[0m     \u001b[38;5;28;01mfor\u001b[39;00m inputs, targets \u001b[38;5;129;01min\u001b[39;00m train_loader:\n\u001b[1;32m      8\u001b[0m         optimizer\u001b[38;5;241m.\u001b[39mzero_grad()\n\u001b[1;32m      9\u001b[0m         outputs\u001b[38;5;241m=\u001b[39mmodel(inputs)\n",
      "File \u001b[0;32m/usr/local/lib64/python3.9/site-packages/torch/utils/data/dataloader.py:701\u001b[0m, in \u001b[0;36m_BaseDataLoaderIter.__next__\u001b[0;34m(self)\u001b[0m\n\u001b[1;32m    698\u001b[0m \u001b[38;5;28;01mif\u001b[39;00m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_sampler_iter \u001b[38;5;129;01mis\u001b[39;00m \u001b[38;5;28;01mNone\u001b[39;00m:\n\u001b[1;32m    699\u001b[0m     \u001b[38;5;66;03m# TODO(https://github.com/pytorch/pytorch/issues/76750)\u001b[39;00m\n\u001b[1;32m    700\u001b[0m     \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_reset()  \u001b[38;5;66;03m# type: ignore[call-arg]\u001b[39;00m\n\u001b[0;32m--> 701\u001b[0m data \u001b[38;5;241m=\u001b[39m \u001b[38;5;28;43mself\u001b[39;49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43m_next_data\u001b[49m\u001b[43m(\u001b[49m\u001b[43m)\u001b[49m\n\u001b[1;32m    702\u001b[0m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_num_yielded \u001b[38;5;241m+\u001b[39m\u001b[38;5;241m=\u001b[39m \u001b[38;5;241m1\u001b[39m\n\u001b[1;32m    703\u001b[0m \u001b[38;5;28;01mif\u001b[39;00m (\n\u001b[1;32m    704\u001b[0m     \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_dataset_kind \u001b[38;5;241m==\u001b[39m _DatasetKind\u001b[38;5;241m.\u001b[39mIterable\n\u001b[1;32m    705\u001b[0m     \u001b[38;5;129;01mand\u001b[39;00m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_IterableDataset_len_called \u001b[38;5;129;01mis\u001b[39;00m \u001b[38;5;129;01mnot\u001b[39;00m \u001b[38;5;28;01mNone\u001b[39;00m\n\u001b[1;32m    706\u001b[0m     \u001b[38;5;129;01mand\u001b[39;00m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_num_yielded \u001b[38;5;241m>\u001b[39m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_IterableDataset_len_called\n\u001b[1;32m    707\u001b[0m ):\n",
      "File \u001b[0;32m/usr/local/lib64/python3.9/site-packages/torch/utils/data/dataloader.py:757\u001b[0m, in \u001b[0;36m_SingleProcessDataLoaderIter._next_data\u001b[0;34m(self)\u001b[0m\n\u001b[1;32m    755\u001b[0m \u001b[38;5;28;01mdef\u001b[39;00m \u001b[38;5;21m_next_data\u001b[39m(\u001b[38;5;28mself\u001b[39m):\n\u001b[1;32m    756\u001b[0m     index \u001b[38;5;241m=\u001b[39m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_next_index()  \u001b[38;5;66;03m# may raise StopIteration\u001b[39;00m\n\u001b[0;32m--> 757\u001b[0m     data \u001b[38;5;241m=\u001b[39m \u001b[38;5;28;43mself\u001b[39;49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43m_dataset_fetcher\u001b[49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43mfetch\u001b[49m\u001b[43m(\u001b[49m\u001b[43mindex\u001b[49m\u001b[43m)\u001b[49m  \u001b[38;5;66;03m# may raise StopIteration\u001b[39;00m\n\u001b[1;32m    758\u001b[0m     \u001b[38;5;28;01mif\u001b[39;00m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_pin_memory:\n\u001b[1;32m    759\u001b[0m         data \u001b[38;5;241m=\u001b[39m _utils\u001b[38;5;241m.\u001b[39mpin_memory\u001b[38;5;241m.\u001b[39mpin_memory(data, \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39m_pin_memory_device)\n",
      "File \u001b[0;32m/usr/local/lib64/python3.9/site-packages/torch/utils/data/_utils/fetch.py:52\u001b[0m, in \u001b[0;36m_MapDatasetFetcher.fetch\u001b[0;34m(self, possibly_batched_index)\u001b[0m\n\u001b[1;32m     50\u001b[0m         data \u001b[38;5;241m=\u001b[39m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39mdataset\u001b[38;5;241m.\u001b[39m__getitems__(possibly_batched_index)\n\u001b[1;32m     51\u001b[0m     \u001b[38;5;28;01melse\u001b[39;00m:\n\u001b[0;32m---> 52\u001b[0m         data \u001b[38;5;241m=\u001b[39m [\u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39mdataset[idx] \u001b[38;5;28;01mfor\u001b[39;00m idx \u001b[38;5;129;01min\u001b[39;00m possibly_batched_index]\n\u001b[1;32m     53\u001b[0m \u001b[38;5;28;01melse\u001b[39;00m:\n\u001b[1;32m     54\u001b[0m     data \u001b[38;5;241m=\u001b[39m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39mdataset[possibly_batched_index]\n",
      "File \u001b[0;32m/usr/local/lib64/python3.9/site-packages/torch/utils/data/_utils/fetch.py:52\u001b[0m, in \u001b[0;36m<listcomp>\u001b[0;34m(.0)\u001b[0m\n\u001b[1;32m     50\u001b[0m         data \u001b[38;5;241m=\u001b[39m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39mdataset\u001b[38;5;241m.\u001b[39m__getitems__(possibly_batched_index)\n\u001b[1;32m     51\u001b[0m     \u001b[38;5;28;01melse\u001b[39;00m:\n\u001b[0;32m---> 52\u001b[0m         data \u001b[38;5;241m=\u001b[39m [\u001b[38;5;28;43mself\u001b[39;49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43mdataset\u001b[49m\u001b[43m[\u001b[49m\u001b[43midx\u001b[49m\u001b[43m]\u001b[49m \u001b[38;5;28;01mfor\u001b[39;00m idx \u001b[38;5;129;01min\u001b[39;00m possibly_batched_index]\n\u001b[1;32m     53\u001b[0m \u001b[38;5;28;01melse\u001b[39;00m:\n\u001b[1;32m     54\u001b[0m     data \u001b[38;5;241m=\u001b[39m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39mdataset[possibly_batched_index]\n",
      "Cell \u001b[0;32mIn[45], line 10\u001b[0m, in \u001b[0;36mClassificationDataset.__getitem__\u001b[0;34m(self, idx)\u001b[0m\n\u001b[1;32m      9\u001b[0m \u001b[38;5;28;01mdef\u001b[39;00m \u001b[38;5;21m__getitem__\u001b[39m(\u001b[38;5;28mself\u001b[39m,idx):\n\u001b[0;32m---> 10\u001b[0m     \u001b[38;5;28;01mreturn\u001b[39;00m \u001b[38;5;28mself\u001b[39m\u001b[38;5;241m.\u001b[39msequences[idx], \u001b[43mtorch\u001b[49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43mtensor\u001b[49m\u001b[43m(\u001b[49m\u001b[38;5;28;43mself\u001b[39;49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43mlabels\u001b[49m\u001b[43m[\u001b[49m\u001b[43midx\u001b[49m\u001b[43m]\u001b[49m\u001b[43m,\u001b[49m\u001b[43m \u001b[49m\u001b[43mdtype\u001b[49m\u001b[38;5;241;43m=\u001b[39;49m\u001b[43mtorch\u001b[49m\u001b[38;5;241;43m.\u001b[39;49m\u001b[43mfloat32\u001b[49m\u001b[43m)\u001b[49m\n",
      "\u001b[0;31mTypeError\u001b[0m: new(): invalid data type 'str'"
     ]
    }
   ],
   "source": [
    "cls_loss_results = {}\n",
    "\n",
    "for name, model in model_cls.items():\n",
    "    print(\"Training {name} for Text Classification\")\n",
    "    optimizer = optim.Adam(model.parameters(), lr=0.001)\n",
    "    cls_loss_results[name] = train_and_evaluate(model, train_loader, criterion_cls, optimizer, epochs=5)\n",
    "\n",
    "plot_losses(cls_loss_results, \"Text Classification Training Loss (RNN vs LSTM)\")"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "e36b991c-fd57-4339-a8c6-77feb34011d5",
   "metadata": {},
   "source": [
    "## 3. **Tuning the model**\n",
    "### a) Modify the LSTM model by changing the embedding dimension and hidden layer size.\n",
    "### b) Train the modified model using the same dataset.\n",
    "### c) Record and compare the training accuracy of the original and modified models\n",
    "### d) State which hyperparameter setting gives better performance and justify your answer"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "0e91bd33-8c5b-4a0e-a6b2-9b3eba54352b",
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "0570b022-3639-42c3-b987-54c3aff2f02c",
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "90c7d7d5-e6d6-4fb1-a0ec-4d5b4c8b00e6",
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "11a841d5-f02c-4cc3-8275-540e0311ac76",
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "5e8f90ed-55bb-409b-9c74-cf156797b9a7",
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.25"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}
