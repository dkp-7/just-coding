// Find nth root of a number (m)   & return -1 if the root is not an integer

Question link : https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


int NthRoot(int n, int m) {

  double root = pow(m, 1.0 / n);

    if (abs(root - round(root)) < 1e-9) {

        return round(root);

    } else {

        return -1;

    }

}


-----------------------------------------------------------------------------------------
  
int NthRoot(int n, int m) {
    
  int low = 1;
  int high = m;

  while(low <= high)
  {
    int mid = (low + high)/2;

    if(pow(mid, n) == m)
      return mid;
    else if(pow(mid, n) > m)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
  
}
