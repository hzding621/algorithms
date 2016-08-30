// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        while (len < n) {
            if (i == nbuf) {
                nbuf = read4(buf4);
                i = 0;
                if (nbuf == 0) break;
            }
            buf[len++] = buf4[i++];
        }
        return len;
        
    }
private:
    int i = 0, nbuf = 0;
    char buf4[4];
};