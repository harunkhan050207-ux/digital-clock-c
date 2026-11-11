#include<stdio.h>
#include<time.h>

void fill_time(char*,int);
int input_format();

int main (){
    char time[50];
    int format = input_format();
    fill_time(time,format);
    printf("Current time: %s", time);
    return 0;

}
int input_format(){
    int format;
    printf("\nchoose the  time format:");
    printf("\n1. 24hour format");
    printf("\n2. 12hour format");
    printf("\nMake a  choice(1/2): ");
    scanf("%d", &format);
    return format;
}
void fill_time(char* buffer,int format){
    time_t raw_time;
    struct tm * current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    if(format == 1){
        strftime(buffer, 50,"%H:%M:%S",current_time);
    }else{
        strftime(buffer, 50,"%I:%M:%S %p",current_time);
    }
}
