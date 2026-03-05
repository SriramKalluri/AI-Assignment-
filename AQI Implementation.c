#include <stdio.h>
#include <string.h>

int main() {

    FILE *file;
    char pollutant[20];
    float value;
    float pm25 = 0;

    file = fopen("aqi_data.txt","r");

    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    while(fscanf(file,"%s %f", pollutant, &value) != EOF){
        if(strcmp(pollutant,"PM2.5")==0)
            pm25 = value;
    }

    fclose(file);

    printf("PM2.5 Level: %.2f\n", pm25);

    if(pm25 <= 50)
        printf("AQI Category: Good\n");
    else if(pm25 <= 100)
        printf("AQI Category: Moderate\n");
    else if(pm25 <= 150)
        printf("AQI Category: Unhealthy for Sensitive Groups\n");
    else if(pm25 <= 200)
        printf("AQI Category: Unhealthy\n");
    else
        printf("AQI Category: Hazardous\n");

    return 0;
}
