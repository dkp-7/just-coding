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
