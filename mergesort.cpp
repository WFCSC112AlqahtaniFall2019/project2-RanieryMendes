#include <iostream>
#include <vector>
using namespace std;

// function declarations
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {

    // test if mergeSort is being called

    if (a.size() == 1 ) {

        return;

    }

    if(right -left >= 1 ) {

    int mid = left + (right - left) / 2;

    mergeSort(a, tmp, left, mid ); // sort L

    mergeSort(a, tmp, mid + 1 , right); // sort Right

    mergeSortedLists(a, tmp, left, mid, right);
}

}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {

    int b = left;

    int c = middle + 1;

    int d = middle;

    int e = right;

    for (int f = left; f < e + 1; f++) {

        if (c > e && b > d) {
            // do nothing
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
    /* your code here */
    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v

    int last = v.size()-1;

    int mid = (0 + last) / 2;

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

/* your code here */
