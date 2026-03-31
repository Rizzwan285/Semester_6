#include <stdio.h>
#include <pthread.h>
#include <string.h>
#define NUM_THREADS 8

typedef struct {
    int thread_id;
    char* input_string;
    int vowel_count;
} thread_data;

int is_vowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

void* count_vowels(void* arg) {
    thread_data* a = (thread_data*)arg;

    for (int i = 0; *((a->input_string)+i)!='\0'; i++) {
        if (is_vowel(*((a->input_string)+i))) a->vowel_count++;
    }

    return NULL;
}

int main() {
    char* input_string[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    thread_data arg[NUM_THREADS];

    input_string[0]= "Computer";
    input_string[1]= "Programming";
    input_string[2]= "Data Science";
    input_string[3]= "Threads";
    input_string[4]= "Algorithm";
    input_string[5]= "Python";
    input_string[6]= "Artificial Intelligence";
    input_string[7]= "Quantum Computing";
    
    for (int i = 0; i < NUM_THREADS; i++) {
        arg[i].thread_id = i+1;
        arg[i].input_string = input_string[i];
        arg[i].vowel_count = 0;
        pthread_create(&threads[i], NULL, count_vowels, &arg[i]);
    } 

    for (int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d: %s -> Vowels = %d\n", arg[i].thread_id, input_string[i], arg[i].vowel_count);
    }

    return 0;
}