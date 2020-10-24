/* Maximum Subarray Sum :
   Given an array of n numbers, our first task is to 
   calculate the maximum subarray sum, i.e., the largest 
   possible sum of a sequence of consecutive values in the
   array.
*/

// O(n^3) Time Solution :
	int best = 0;
	for (int a = 0; a < n; a++){
		for (int b = a; b < n; b++){
			int sum = 0;
			for (int k = a; k <= b; k++){
				sum += array[k];
			}
			best = max( best, sum);
		}
	}
	cout << best << "\n";

// O(n^2) Time Solution :
	int best = 0;
	for (int a = 0; a < n; a++){
		int sum = 0;
		for (int b = a; b < n; b++){
			sum += array[k];
			best = max( best, sum)
		}
	}
	cout << best << "\n";

// O(n) Time Solution :
	int best = 0;
	for(int k = 0; k < n; k++){
		sum = max( array[k], sum + array[k]);
		best = max( best, max);
	}
	cout << best << "\n";