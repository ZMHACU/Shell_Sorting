/*Worst-Case : O(n^2)
  Average-Case : O(n^2)
  Best-Case : O(n log n)
*/


#include<iostream>
using namespace std;

void ShellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){    //Loop ini untuk mengatur nilai awal gap, lalu dibagi 2 hingga gap = 1. Gap untuk menentukan jarak antar elemen yang akan dibandingkan dan ditukar
        for (int j = gap; j < n; j+=1){        //Looping dari index gap hingga akhir array
            int temp = arr[j];
            int i = 0;
/*Proses pergeseran elemen ke kanan jika elemen sebelumnya (arr[i - gap]) lebih besar dari temp.
Seperti insertion sort, tapi lompatannya adalah gap (bukan 1).
Ini membuat elemen besar "digeser" ke kanan agar temp bisa disisipkan di tempat yang benar.*/

            for ( i = j; (i >= gap) && (arr[i- gap]>temp); i-=gap){  
                arr[i] = arr[i-gap];
            }
            arr[i] = temp; 
        }
    }  
}

int main(){
    int n;
    cout<<"Enter the size of the array: "<<endl; //Memasukkan ukuran array yang diinginkan
    cin>>n;
    int arr1[n];

    //Memasukkan angka random ke dalam array
    cout<<"Enter "<<n<<" integers in any order"<<endl;
    for (int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    cout<<endl<<"Before Sorting: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl<<endl<<"SHELL SORT"<<endl<<endl;
    ShellSort(arr1, n);                 //Pemanggilan Fungsi ShellSort

    cout<<"After Sorting: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}
