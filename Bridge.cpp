#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
using namespace std;

int thread_amount = 25;
bool* choose = new bool[thread_amount]{false};
string str;

class bake{
public:
    int* arr;
    int am;

    bake(){
        am = 0;
        arr = NULL;
    }
    bake(int am){
        arr = new int[am]{0};
        this->am = am;
    }

    void makearr(int am){
        arr = new int[am]{0};
        this->am = am;
    }

    int max(int x){
        choose[x] = true;
        int max;
        for(int i = 0; i < am; i++){
            if (i == 0){
                max = arr[i];
            }
            else if(max < arr[i]){
                max = arr[i];
            }
        }
        choose[x] = false;
        return max + 1;
    }
};
bake token(thread_amount);

void* childthread(void* val){
    int* temp = (int*)val;
    int ind = *temp;
    cout << "\nind is " << ind << endl;
    sleep(1);

    for (int x = 0; x < 15; x++){
        
        token.arr[ind] = token.max(ind);
               
        for (int i = 0; i < token.am; i++){
            if (i == ind){
                continue;
            }
            while (choose[i] == true);
            while (token.arr[i] != 0 && token.arr[i] < token.arr[ind]);
        }
        str = "temp ";
        str += to_string(ind);
        cout << str << endl;
        token.arr[ind] = 0;
        usleep(100);
    }
    
    pthread_exit(NULL);
}


int main(){
    pthread_t* pid = new pthread_t[thread_amount];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    int* x = new int;
    for (int i = 0; i < thread_amount; i++){
        *x = i;
        pthread_create(&pid[i], &attr, childthread, (void*)x);
        usleep(20);
    }
    sleep(5);
}



