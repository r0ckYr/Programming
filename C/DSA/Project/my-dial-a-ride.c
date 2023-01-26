#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define MAX_LOCATIONS 100  // maximum number of locations
#define MAX_VEHICLES 25    // maximum number of vehicles
#define MAX_CAPACITY 5     // maximum capacity of a vehicle
#define MAX_REQUESTS 5000  // maximum number of passenger requests
#define MAX_TIME 1440      // maximum time in a day in minutes
#define AVERAGE_SPEED 2    // averate speed minutes per kilometer
#define BASE_RATE 1        // base rate rupees per KM


// structure to represent a passenger request
typedef struct {
  int pickup_location;  // pickup location ID
  int dropoff_location; // dropoff location ID
  int pickup_time;      // pickup time (in minutes)
  int dropoff_time;     // dropoff time (in minutes)
} Request;

// structure to represent a vehicle
typedef struct {
  int location;         // current location ID
  int time;             // current time (in minutes)
  int capacity;
  int* route;           // array to store the route
  int route_length;     // length of the route
} Vehicle;

void display(int n, int N, int R, int distance_matrix[n][n], Vehicle *vehicles, Request *requests)
{
    printf("\nDistance Matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            printf("%d ", distance_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nVehicles Location :\n");
    for(int i=0;i<N;i++)
    {
        printf("%d - %d\n", i, vehicles[i].location);  
    }
    printf("\n");
    printf("\nRequests:\n");
    for(int i=0;i<R;i++)
    {
        // input a request : pickupLocation dropoffLocation pickupTime dropoffTime
        printf("%d %d %d %d\n", requests[i].pickup_location, requests[i].dropoff_location, requests[i].pickup_time, requests[i].dropoff_time);   
    }
    printf("\n");

}


void sortRequests(int N, Request *requests)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(requests[j].pickup_time > requests[j+1].pickup_time)
            {
                Request temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }
}


int main()
{
    int n=0, N=0, c=0, R=0;
    Vehicle vehicles[MAX_VEHICLES];
    Request requests[MAX_REQUESTS];

    //start reading inputs
    scanf("%d %d %d %d", &n, &N, &c, &R); // number_of_locations number_of_vehicles capacity_of_vehicle number_of_requests
    int distance_matrix[n][n]; // matrix to store distances between locations
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            //input distance from location 'i' to location 'j'
            scanf("%d", &distance_matrix[i][j]);
        }
    }

    for(int i=0;i<N;i++)
    {
        //input location at which vehicle 'i' is at midnight
        scanf("%d", &vehicles[i].location);  
        vehicles[i].time = 0;
        vehicles[i].capacity = c;
    }

    for(int i=0;i<R;i++)
    {
        // input a request : pickupLocation dropoffLocation pickupTime dropoffTime
        scanf("%d %d %d %d", &requests[i].pickup_location, &requests[i].dropoff_location, &requests[i].pickup_time, &requests[i].dropoff_time);   
    }

    //sort passenger requests in ascending order of pickup time to schedule vehicles
    sortRequests(R, requests);

    //dispaly function to check input
    display(n, N, R, distance_matrix, vehicles, requests);



}
