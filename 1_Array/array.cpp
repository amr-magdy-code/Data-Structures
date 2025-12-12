/*
  Arrays
  - What Is Array ?
  --- Collection Of Elements Of The Same Type
  --- Placed in Contiguous Memory Locations
  --- Referenced By Index Started From 0
  - Why We Need Array ?
  - Creating Array Syntax
  - Check Array Size
  - Create Array Without Size
*/

using namespace std;
#include <iostream>
#include<array>

int main()
{
	int nums[4] = { 100, 200, 300, 400 };
	cout << sizeof(int) << "\n";  // 4 Bytes
	cout << sizeof(nums) << "\n"; // 16 Bytes

	double dos[4] = { 100, 200, 300, 400 };
	cout << sizeof(double) << "\n"; // 8 Bytes
	cout << sizeof(dos) << "\n";    // 32 Bytes

	cout << "sizeof array is : " << sizeof(nums) / sizeof(int) << endl;


	cout << "===========================" << endl;

	int rands[]{ 100, 5000, 950 };
	cout << rands[0] << "\n";
	cout << rands[1] << "\n";
	cout << rands[2] << "\n";

	cout << "sizeof array is : " << sizeof(rands) / sizeof(rands[0]) << endl;

	cout << "===========================" << endl;
	/*
	- Access Array Elements
	- Check Element Location
	_ modify array element
	*/
	int number[]{ 100, 200, 300 };

	cout << "First Element: " << number[0] << "\n";
	cout << "Last Element: " << number[2] << "\n"; // Number Of Elements - 1

	cout << "Location: " << &number[0] << "\n";
	cout << "Location: " << &number[1] << "\n";
	cout << "Location: " << &number[2] << "\n";

	cout << "sizeof array is : " << sizeof(number) / sizeof number[1] << endl;

	cout << "===========================" << endl;

	string a[] = { "amr","magdy", "hello coder" };
	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	cout << sizeof(a) / sizeof(string) << endl;

	cout << "===========================" << endl;
	/*
	- Declare Empty Array
	- Add Elements To Array
	- Update Array Elements
	- Get Length Of Array With Sizeof
	*/

	int grade[4];

	grade[3] = 400; // Last Element
	grade[0] = 100; // First Element
	grade[1] = 200; // Second Element
	grade[2] = 300; // Third Element

	cout << "Element 1: " << grade[0] << "\n";  //100
	cout << "Element 2: " << grade[1] << "\n";  //200
	cout << "Element 3: " << grade[2] << "\n";  //300
	cout << "Element 4: " << grade[3] << "\n";  //400

	grade[1] = 1000; // Second Element  

	cout << "Element 2: " << grade[1] << "\n";

	int anum[] = { 100, 200, 300, 400, 500, 600 }; // 24 / 4 = 6
	cout << "Array Elements Count Is " << sizeof(anum) / sizeof(anum[0]) << endl;

	cout << "===========================" << endl;

	int x[3] = { 0,1 };

	cout << x[0] << endl;
	cout << x[1] << endl;
	cout << x[2] << endl;

	cout << "===========================" << endl;
	/*
  Arrays
	- Two Dimensional Arrays AKA [2D Array]

	Search For
	- Matrix Operations
	- 3D Array
   */
	int points_a[3] = { 1, 2, 3 };
	int points_b[3] = { 4, 5, 6 };
	int points_c[3] = { 7, 8, 9 };

	// Good Practice

	const int rows = 3;
	const int columns = 3;
	int points[rows][columns] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	cout << points[1][2] << "\n"; // 6
	cout << points[2][0] << "\n"; // 7
	cout << points[2][2] << "\n"; // 9

	// Bad Practice
	// int points[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// cout << points[1][2] << "\n"; // 6
	// cout << points[2][0] << "\n"; // 7
	// cout << points[2][2] << "\n"; // 9

	cout << "===========================" << endl;

	int mynumbers[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	cout << mynumbers[0][0] << endl;  // 1
	cout << mynumbers[0][2] << endl;  // 3
	cout << mynumbers[1][0] << endl;  // 5
	cout << mynumbers[1][2] << endl;  // 7
	cout << mynumbers[2][0] << endl;  // 9
	cout << mynumbers[2][2] << endl;  // 11

	cout << "===========================" << endl;

	int b[2][2] = { {5,6},{8,9} };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << b[i][j] << endl;
		}
	}


	cout << "===========================" << endl;


	int age[5];
	cout << "Enter 5 ages: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Age " << (i + 1) << ": ";
		cin >> age[i];
	}
	cout << "sum of array" << endl;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += age[i];
	}
	cout << sum << endl;
	cout << "===========================" << endl;


	int amr[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Enter element at position [" << i << "][" << j << "]: ";
			cin >> amr[i][j];
		}
	}

	/*
 Arrays
	- Array Class
	- Test Method
 Syntax
	Template<Type, Size> Identifier;
	*/

	array<int, 4> score = { 1, 2, 3,4 };

	cout << score[0] << endl;
	cout << score[1] << endl;
	cout << score[2] << endl;
	cout << score[3] << endl;
	cout << "array size is : " << score.size() << endl;

	score.fill(100);
	cout << score[0] << endl;
	cout << score[1] << endl;
	cout << score[2] << endl;
	cout << score[3] << endl;


	score.fill('a');
	cout << score[0] << endl;
	cout << score[1] << endl;
	cout << score[2] << endl;
	cout << score[3] << endl;


	score.fill(true);
	cout << score[0] << endl;
	cout << score[1] << endl;
	cout << score[2] << endl;
	cout << score[3] << endl;


	cout << "===========================" << endl;

	/*
	  Arrays
	  - Useful Methods
	  --- at
	  --- front
	  --- back
	  --- fill
	  --- size
	  --- empty
	*/

	array<int, 4> metho = { 100, 200, 300, 400 };
	cout << metho[0] << "\n";      // 100
	cout << metho.front() << "\n"; // 100
	cout << metho[3] << "\n";      // 400
	cout << metho.back() << "\n";  // 400
	cout << metho.at(2) << "\n";   // 300
	cout << metho.size() << "\n";  // 4
	cout << metho.empty() << "\n"; // 0 => False

	cout << "===========================" << endl;
	/*
  Arrays
  - Insert Element At Specific Position In Array
  - Shift Elements To The Right
  - Manually Dynamic Array
  */


	const int MAX_SIZE = 100;   // ???? ??? ???? (?? ???????? ????)
	int size = 5;               // ????? ?????? ?????? ???????
	int arr[MAX_SIZE] = { 10, 20, 30, 40, 50 };

	int element, index;

	cout << "Array before editing:\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "Enter the element that you want to insert: ";
	cin >> element;

	cout << "Enter its index: ";
	cin >> index;

	if (index < 0 || index > size)
	{
		cout << "Index out of range\n";
	}
	else
	{
		// shift elements to the right
		for (int i = size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}

		arr[index] = element; // ?? ?????? ?? ?????

		size++; // ????? ????? ??????
	}

	cout << "\nArray after editing:\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;

	cout << "===========================" << endl;
	/*
  Arrays
  - Search In Array
  - Linear Search Algorithm
  */

	int ar[5] = { 10, 20, 30, 40, 50 };
	for (int i = 0; i < 5; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
	cout << "search in array " << endl;
	int target;
	cin >> target;
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (ar[i] == target) {
			found = true;
			cout << "Element found " << endl;
			cout << "at index : " << i << endl;
			break;
		}
	}
	if (!found) {
		cout << "Element not found in the array." << endl;
	}

	cout << "===========================" << endl;

	/*
  Arrays
  - Delete Element From Array At Specific Index
  - Shift Elements To The Left
  - Manually Dynamic Array
  */













	return 0;
}
