#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char *songs[] = {
    "Song 1: Faded",
    "Song 2: Animals",
    "Song 3: Shot Me Down",
    "Song 4: Turn Down For What",
    "Song 5: Firebeatz: Bazooka",
    "Song 6: New World: Flute",
    "Song 7: Belik Boom: Avada Kedavra",
    "What are you looking for..!!",
    "What are you looking for..!!",
    "What are you looking for..!!",
    "The End",
    "Song Not Available",
};

const int NUM_SONGS = (sizeof(songs)/sizeof(char*));


void get_the_song(size_t number){
    if(number > NUM_SONGS - 1 || number < 0){
        printf("%s\n",songs[NUM_SONGS - 1]);
    }
    else{
        printf("%s\n",songs[number]);
    }
}

int main(){
    get_the_song(1);
    get_the_song(2);
    get_the_song(0);
    get_the_song(10000);
    get_the_song(-1);
    return 0;
}