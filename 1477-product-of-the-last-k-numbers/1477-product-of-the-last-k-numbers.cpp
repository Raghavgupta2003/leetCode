// class ProductOfNumbers {
// public:
//     vector<int> v;
//     ProductOfNumbers() {
//     }
    
//     void add(int num) {
//         v.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int pdt = 1;
//         for(int i=v.size()-k; i<v.size();i++){
//             pdt *= v[i];
//         }
//         return pdt;
//     }
// };
//-----------------------------------------------------------

class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int pdt = 1;
        for(int i=v.size()-k; i<v.size();i++){
            pdt *= v[i];
        }
        return pdt;
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */