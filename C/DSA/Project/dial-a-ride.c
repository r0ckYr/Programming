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

// structure to represent a location
typedef struct {
  int id;               // location ID
  int x;                // x-coordinate
  int y;                // y-coordinate
} Location;

// structure to represent a passenger request
typedef struct {
  int pickup_location;  // pickup location ID
  int dropoff_location; // dropoff location ID
  int pickup_time;      // pickup time (in minutes)
  int dropoff_time;     // dropoff time (in minutes)
} Request;

// structure to represent a vehicle
typedef struct {
  int id;               // vehicle ID
  int location;         // current location ID
  int time;             // current time (in minutes)
  int capacity;         // current capacity
  int* route;           // array to store the route
  int route_length;     // length of the route
} Vehicle;

// function to compute the Euclidean distance between two locations
int distance(Location a, Location b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return (int)sqrt(dx*dx + dy*dy);
}

// function to find the shortest route for a vehicle to visit a set of locations
void find_route(Vehicle* vehicle, Location* locations, int num_locations, int* visited, int num_visited) {
  // base case: all locations have been visited
  if (num_visited == num_locations) {
    // compute the total distance of the route
    int route_distance = distance(locations[vehicle->location], locations[vehicle->route[0]]);
    for (int i = 0; i < num_locations - 1; i++) {
      route_distance += distance(locations[vehicle->route[i]], locations[vehicle->route[i+1]]);
    }
    // update the vehicle's route and route length if the current route is shorter
    if (route_distance < vehicle->route_length) {
      vehicle->route_length = route_distance;
      memcpy(vehicle->route, visited, num_locations * sizeof(int));
    }
    return;
  }
  // recursive case: visit the remaining locations in all possible orders
  for (int i = 0; i < num_locations; i++) {
    if (!visited[i]) {
      visited[i] = true;
      //here
      find_route(vehicle, locations, num_locations, visited, num_visited+ 1);
      visited[i] = false;
    }
  }
}

int main(int argc, char** argv) {
  // read the input data
  int num_locations;
  scanf("%d", &num_locations);
  Location locations[MAX_LOCATIONS];
  for (int i = 0; i < num_locations; i++) {
    scanf("%d %d", &locations[i].x, &locations[i].y);
    locations[i].id = i;
  }
  int distance_matrix[MAX_LOCATIONS][MAX_LOCATIONS];
  for (int i = 0; i < num_locations; i++) {
    for (int j = 0; j < num_locations; j++) {
      scanf("%d", &distance_matrix[i][j]);
    }
  }
  int num_vehicles;
  scanf("%d", &num_vehicles);
  int vehicle_capacity;
  scanf("%d", &vehicle_capacity);
  Vehicle vehicles[MAX_VEHICLES];
  for (int i = 0; i < num_vehicles; i++) {
    scanf("%d %d", &vehicles[i].location, &vehicles[i].time);
    vehicles[i].id = i;
    vehicles[i].capacity = vehicle_capacity;
    vehicles[i].route_length = INT_MAX;
    vehicles[i].route = malloc(num_locations * sizeof(int));
  }
  int num_requests;
  scanf("%d", &num_requests);
  Request requests[MAX_REQUESTS];
  for (int i = 0; i < num_requests; i++) {
    scanf("%d %d %d %d", &requests[i].pickup_location, &requests[i].dropoff_location, &requests[i].pickup_time, &requests[i].dropoff_time);
  }

  // assign vehicles to passenger requests
  for (int i = 0; i < num_requests; i++) {
    // find the vehicle with the earliest arrival time at the pickup location
    int min_arrival_time = INT_MAX;
    int min_vehicle_index = -1;
    for (int j = 0; j < num_vehicles; j++) {
      Vehicle* v = &vehicles[j];
      int arrival_time = v->time + distance_matrix[v->location][requests[i].pickup_location];
      if (arrival_time <= requests[i].pickup_time && arrival_time < min_arrival_time) {
        min_arrival_time = arrival_time;
        min_vehicle_index = j;
      }
    }
    // assign the request to the vehicle if it is available
    if (min_vehicle_index != -1) {
      Vehicle* v = &vehicles[min_vehicle_index];
      v->location = requests[i].dropoff_location;
      //here
      v->time = requests[i].dropoff_time + distance_matrix[requests[i].dropoff_location][requests[i].pickup_location];
      v->capacity--;
    }
  }

  // compute the routes for the vehicles
  for (int i = 0; i < num_vehicles; i++) {
    Vehicle* v = &vehicles[i];
    // find the locations that have not been visited by the vehicle
    int visited[MAX_LOCATIONS];
    memset(visited, 0, num_locations * sizeof(int));
    visited[v->location] = true;
    for (int j = 0; j < num_requests; j++) {
      if (requests[j].pickup_location == v->location || requests[j].dropoff_location == v->location) {
        visited[requests[j].pickup_location] = true;
        visited[requests[j].dropoff_location] = true;
      }
    }
    // find the shortest route for the vehicle to visit the remaining locations
    find_route(v, locations, num_locations, visited, num_locations - v->capacity);
  }

  // compute the total distance traveled by the vehicles and the total revenue
  int total_distance = 0;
  int total_revenue = 0;
  for (int i = 0; i < num_vehicles; i++) {
    Vehicle* v = &vehicles[i];
    total_distance += v->route_length;
    total_revenue += v->route_length;
  }

  // print the results
  printf("Total distance traveled: %d\n", total_distance);
  printf("Total revenue: %d\n", total_revenue);

  return 0;
}



