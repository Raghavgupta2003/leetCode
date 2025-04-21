class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        //if we have first element of hidden sequence we can find next elements by adding differences[i]
        //we assume first element to be 0
        //we proceed further to make hidden sequence, but always store minimum ans maximum element from the hidden sequence

        long long a = 0;
        long long max_val = 0;
        long long min_val = 0;
        for(int i=0; i<differences.size(); i++){
            a += differences[i];

            max_val = max(max_val, a);
            min_val = min(min_val, a);
        }

        // after getting first array we only need to add constant to it
        // and we get next sequence.
        //but max_val not exceed then upper
        //and min_val not less than lower

        //max_val + x <= upper
        //min_val + x >= lower

        //in other words
        //x <= Upper-max_val
        //x >= Lower-min_val

        // so, x is [ Lower-min_val, Upper-max_val]

        //means we can add ((Upper-max_val)-(Lower-min_val))
        //and one older subsequence
        // so, ans is ((Upper-max_val)-(Lower-min_val))+1

        // but, if this is < 0 means no such subseq exit return 0

        if(((upper-max_val)-(lower-min_val))+1 < 0) return 0;

        return ((upper-max_val)-(lower-min_val))+1;

    }
};