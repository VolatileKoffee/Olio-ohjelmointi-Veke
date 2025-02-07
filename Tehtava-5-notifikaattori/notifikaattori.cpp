#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori() // constructor
{
    cout << "Initializing Notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *fptr) // head points to the added object and it points to previously first node
{
    fptr->next = seuraajat; // assigning value to next pointer of fptr (follower pointer) using "->"
    seuraajat = fptr;

    cout << "Notifikaattori adds follower: " << seuraajat->getNimi() << endl;
}

void Notifikaattori::poista(Seuraaja *dlt) // skips object = its predecessor next is modified to point to the following object
{
    // checking if the list is empty
    if (seuraajat == nullptr) {
        cout << "The list is empty!" << endl; // for debug purposes
        return;
    }

    // checks if the first node is the one to-be-deleted
    if (seuraajat == dlt) {
        seuraajat = seuraajat->next;
        cout << "Notifikaattori deleted follower: " << dlt->getNimi() << endl;
        return;
    }

    // checks the whole list for to-be-deleted nodes
    Seuraaja *temp = seuraajat;             // temp is current node

    while (temp->next != nullptr) {         // continuing list as long as next node is not NULL
        if (temp->next == dlt) {            // checking if next node is to-be-deleted node
            temp->next = temp->next->next;  // moving over "deleted" node to the next one
            cout << "Notifikaattori deleted follower: " << dlt->getNimi() << endl;
            return;
        }
        temp = temp->next;      // continuing list
    }
}

void Notifikaattori::tulosta()
{
    cout << "Notifikaattori followers: " << endl;

    Seuraaja *printout = seuraajat; // printout -pointer
    while (printout != nullptr) {
        cout << "Name of follower: " << printout->getNimi() << endl;
        printout = printout->next;
    }
}

void Notifikaattori::postita(string msg) // shares parameter with paivitys()-function
{
    // checks if the posting list is empty
    if (seuraajat == nullptr) {
        cout << "Nothing to post!" << endl; // for debug purposes
        return;
    }

    cout << "Notifikaattori posts message: " << msg << endl;

    Seuraaja *postIt = seuraajat;   // postIt -pointer
    while(postIt != nullptr) {
        postIt->paivitys(msg);      // calling every follower's paivitys() -function
        postIt = postIt->next;
    }
}
