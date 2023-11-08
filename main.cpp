
#include "slist.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */
Airport *AUS();
void quickSort(slist *airports, Node *low, Node *high);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
int main() {

  slist *airportList = new slist();
  ifstream infile;
  int i = 0;
  char cNum[256];
  char type[256];
  char name[256];
  char line[256];
  // Airport *airportArr[13500]; // Replace array with Linked List

  int airportCount;
  Airport *a[13500];
  Airport *austin = new Airport();
  infile.open("airport-codes_US.csv", ifstream::in);
  if (infile.is_open()) {
    int c = 0;
    string a;

    while (infile.good()) {
      // data inserted into linked list

      Airport *air = new Airport();
      infile.getline(air->code, 256, ',');
      // cout << air->code << endl;
      infile.getline(type, 256, ',');
      // cout << type << endl;
      infile.getline(name, 256, ',');
      // cout << name << endl;
      infile.getline(cNum, 256, ',');
      air->longitude = atof(cNum);
      // cout << air->longitude << endl;
      infile.getline(cNum, 256, ',');
      air->latitude = atof(cNum);
      // cout << air->latitude << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, ',');
      // cout << line << endl;
      infile.getline(line, 256, '\n');
      // cout << line << endl << endl;

      if (c != 0) {
        airportList->add(air);
        // cout << "read" << endl;
      }

      // if (!(c % 1000))
      //   cout << air->code << " long: " << air->longitude
      //        << " lat: " << air->latitude << endl;
      // cout << air->code << " long: " << air->longitude
      //    << " lat: " << air->latitude << endl;
      // cout << austin->code << " long: " << austin->longitude
      //    << " lat: " << austin->latitude << endl;
      //    cout << "Distance between " << air->code << " and " << austin->code
      //    << " is "
      //    << distanceEarth(air->longitude, air->latitude,
      //                     austin->longitude, austin->latitude)
      //    << endl;
      // if (!(c % 1000))
      // {
      //     cout << airportArr[c]->code << " long: " <<
      //     airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<
      //     endl; cout << airportArr[c+1]->code << endl; //" long: " <<
      //     airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude
      //     <<  endl;
      // }

      i++;
      c++;
    }
    airportCount = c - 1;
    infile.close();
    // cout << "[reading array]" << endl;
    // for (int c = 0; c < airportCount; c++)
    //   if (!(c % 1000)) {
    //     cout << airportArr[c]->code << " long: " << airportArr[c]->longitude
    //          << " lat: " << airportArr[c]->latitude << endl;
    //     cout << airportArr[c + 1]->code
    //          << " long: " << airportArr[c + 1]->longitude
    //          << " lat: " << airportArr[c + 1]->latitude << endl;
    //     cout << "Distance between " << airportArr[c]->code << " and "
    //          << airportArr[c + 1]->code << " is "
    //          << distanceEarth(airportArr[c]->longitude,
    //          airportArr[c]->latitude,
    //                           airportArr[c + 1]->longitude,
    //                           airportArr[c + 1]->latitude)
    //          << endl;
    //   }
    // SORTING LINKED LIST
    quickSort(airportList, airportList->head, airportList->tail);
    Airport *austin = AUS(); // Austin Airport
    // austin->code[0] = 'A';
    // austin->code[1] = 'U';
    // austin->code[2] = 'S';
    // austin->longitude = 97.1394;
    // austin->latitude = 30.2672;
    Node *iter = airportList->get(0);
    int count = 1;
    for (int i = 0; i < airportList->size(); i++) {
      cout << iter->data->code << " long: " << iter->data->longitude
           << " lat: " << iter->data->latitude << endl;
      cout << austin->code << " long: " << austin->longitude
           << " lat: " << austin->latitude << endl;
      cout << "Distance between " << iter->data->code << " and " << austin->code
           << " is "
           << distanceEarth(iter->data->longitude, iter->data->latitude,
                            austin->longitude, austin->latitude)
           << endl;
      if ((distanceEarth(iter->data->longitude, iter->data->latitude,
                         austin->longitude, austin->latitude) /
           1.609) <= 100) {
        count++;
      }
      iter = iter->next;
    }
    cout << endl << count - 1 << " airports within 100 miles";
  } else {
    cout << "Error opening file";
  }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) { return (deg * pi / 180); }

//  This function converts radians to decimal degrees
double rad2deg(double rad) { return (rad * 180 / pi); }

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */

double distanceEarth(double lon1d, double lat1d, double lon2d, double lat2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r) / 2);
  v = sin((lon2r - lon1r) / 2);
  return 2.0 * earthRadiusKm *
         asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
        Provide sort routine on linked list
*/

Node *partition(slist *airportList, Node *low, Node *high) {
  Airport *austin1 = AUS();
  Node *pivot = low;
  Node *front = low;
  int temp = 0;
  while (front != NULL && front != high && low != nullptr && high != nullptr) {
    // cout << front->data->code << " " << high->data->code << endl;
    double frontDist =
        distanceEarth(front->data->longitude, front->data->latitude,
                      austin1->longitude, austin1->latitude);
    double highDist = distanceEarth(high->data->longitude, high->data->latitude,
                                    austin1->longitude, austin1->latitude);

    if (frontDist < highDist) {
      pivot = low;

      airportList->exchange(low, front);

      low = low->next;
    }
    front = front->next;
  }
  airportList->exchange(low, high);
  return pivot;
}
void quickSort(slist *airportList, Node *low, Node *high) {
  if (low == high) {
    return;
  }
  Node *pivot = partition(airportList, low, high);

  if (pivot != NULL && pivot->next != NULL) {
    quickSort(airportList, pivot->next, high);
  }

  if (pivot != NULL && low != pivot) {
    quickSort(airportList, low, pivot);
  }
}

Airport *AUS() {
  Airport *austin1 = new Airport(); // Austin Airport
  austin1->code[0] = 'A';
  austin1->code[1] = 'U';
  austin1->code[2] = 'S';
  austin1->longitude = -97.1394;
  austin1->latitude = 30.2672;

  return austin1;
}