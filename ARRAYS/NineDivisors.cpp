#define ll long long int
class Solution {
  public:
    ll power(ll a, int n){
        ll val = 1;
        for(int i =0; i<8; i++){
            val*=a;
            if(val>n)
                return false;
        }
        return true;
    }
    
    
    int countNumbers(int n) {
        // Code Here
        int res = 0;
        int limit = sqrt(n);
        vector<bool>isprime(n+1, true);
        isprime[1]=false;
        for(int i = 2; i*i <= limit; i++){
            if(isprime[i]==true){
                for(int j = 2*i ; j<=limit; j+=i){
                    isprime[j] = false;
                }
            }
        }
        vector<ll>primes;
        for(ll i=2; i<=limit; i++){
            if(isprime[i]==true)
                primes.push_back(i);
        }
        for(int i =0; i<primes.size(); i++){
            ll a = primes[i];
            if(power(a, n))
                res++;
            else
                break;
        }
        for(int i =0; i<primes.size(); i++){
            for(int j = i+1; j<primes.size(); j++){
                ll a = primes[i];
                ll b = primes[j];
                ll val = a*a*1LL*b*b;
                if(val <=n){
                    res++;
                }
            }
        }
        return res;
    }
};
