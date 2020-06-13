//
// Created by nivtal9 on 9.6.2020.
//

#ifndef ITERTOOLS_CFAR_A_RANGE_HPP
#define ITERTOOLS_CFAR_A_RANGE_HPP
using namespace std;
namespace itertools {
    //template <typename T>
    class range {
    private:
        int bottom;
        int top;
    public:
        range(int x, int y) : bottom(x), top(y) {
            //adding methods later
        }

        //inner class iterator begin
        class iterator{
        private:
            int cur;
        public:
            iterator(int curr): cur(curr){}
            bool operator==(const iterator &ite) const {
                return cur == ite.cur;
            }

            bool operator!=(const iterator &ite) const {
                return cur != ite.cur;
            }
            iterator &operator++ () {
                cur += 1;
                return *(this);
            }
            const iterator operator++ (int) {
                iterator t = *(this);
                cur = cur + 1;
                return t;
            }
            iterator &operator-- () {
                cur += - 1;
                return *(this);
            }
            const iterator operator-- (int) {
                iterator t = *(this);
                cur += - 1;
                return t;
            }
            int operator*() {
                return cur;
            }
        };
        //inner class iterator end
        iterator begin() {
            return bottom;
        }

        iterator end() {
            return top;
        }
    };

}
#endif //ITERTOOLS_CFAR_A_RANGE_HPP
