#include <iostream>
#include <vector>
using namespace std;

// function declarations
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {

    // int left = first index of the vector

    // int right = last index of the vector

    // if branch to test for base case

    if (a.size() == 1 ) {

        return;

    }

    // if branch to execute until virtually divide the vector into just one element

    if(right -left >= 1 ) {

    int mid = left + (right - left) / 2;

    mergeSort(a, tmp, left, mid ); // call mergeSort to sort L (vector's left half)

    mergeSort(a, tmp, mid + 1 , right); // call mergeSort to sort R (vector's right half)

    // call mergeSortedList to merge and sort the two lists (L and R) together
    mergeSortedLists(a, tmp, left, mid, right);
}

}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {

    int b = left;    // int b = to the first index of the list

    int c = middle + 1; // int c = to the index middle +1 of the list

    int d = middle; // int d = to the middle of the list

    int e = right; // int e  = to the last index of the list


    // for loop to allocate the elements (sorted) into the vector tmp through the use if and else-if branches

    for (int f = left; f < e + 1; f++) {

        // if and else-if branches bellow are used to allocate the vector a's elements into the tmp vector, storing such elements in order.



        if (c > e && b > d) {

            /* If branch to do nothing  if the expressions  index middle + 1 > the last index of the list
         * and index of vector's first element >  index of middle element evaluate to true */

        }
        else if (c > e) {
            tmp.at(f) = a.at(b);
            b++;
        }
        else if (b > d) {
            tmp.at(f) = a.at(c);
            c++;
        }
        else if (a.at(b) > a.at(c)) {
            tmp.at(f) = a.at(c);
            c++;
        }
        else if (a.at(b) <= a.at(c)) {
            tmp.at(f) = a.at(b);
            b++;
        }
    }

    // for loop to correctly allocate  the elements stored in tmp into vector a

  for (int p = left; p < right +1 ; p++) {

    a.at(p) = tmp.at(p);

    }


}


int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace


    // unit test for merge
    //It uses both testbench and assert function to test mergeSortedList

    //initializing vector for test mergeSortedList

    vector <int> test = {9, 89, 71, 45, 1, 52, 37, 16};
    vector <int> tmp_test;  // temporary workspace for unit test
    tmp_test.resize(8);

    mergeSort(test, tmp_test, 0,7); // call merge sort that will call mergeSortedList within it and it will test this later function.
    mergeSortedLists(test, tmp_test, 0, 3, 7); // call mergeSortedListed to be tested below.

    // TESTING through assert function if mergeSortedList worked, that is, check if the list is sorted
    for(int i = 1; i < test.size(); i++)
        assert(test.at(i-1) <= test.at(i));



    cout << "Unit test" << endl << endl << "Testing mergeSortedList" << endl;
    cout << endl << "Unsorted List: 9 89 71 45 1 52 37 16 " << endl << "Expected Sorted List: 1 9 16 37 45 52 71 89" << endl;
    //testing THROUGH testbench
    cout << endl << "mergeSortedList works. It obtained: ";
    for(int i = 0; i < test.size(); i++) {
        cout << test.at(i) << '\t';
    }

    cout << endl << endl;


    // initialize and print input

    cout << "Program running: " << endl;

    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v

    int last = v.size()-1; // get the index of v's last element

    int mid = (0 + last) / 2; // get the index of v's middle element

    //call mergeSort to sort the vector v

    mergeSort(v,t,0, last);



    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }

    cout <<  endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}


