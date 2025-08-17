class StringIterator {
public:
    int idx, ct, n;
    char cur;
    string s;
    StringIterator(string compressedString) {
        s = compressedString;
        n = compressedString.size();
        ct = 0;
        idx = 0;
        cur = ' ';
    }
    
    char next() {
        if(!hasNext()) return ' ';
        if(ct == 0) {
            cur = s[idx++];
            while(idx < n && s[idx] >= '0' && s[idx] <= '9') {
                ct = (ct * 10) + (s[idx++] - '0');
            }
        }
        ct--;
        return cur;
    }
    
    bool hasNext() {
        return (idx < n || ct != 0);
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */