//
// Created by nivtal9 on 9.6.2020.
//

#ifndef ITERTOOLS_CFAR_A_COMPRESS_HPP
#define ITERTOOLS_CFAR_A_COMPRESS_HPP
//using namespace std;
namespace itertools {
    class compress {
    private:
        int bottom;
        int top;
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
    public:
        template <class T> compress(T) {
                //adding code later
        }
        template <typename Func,class T> compress(Func, T) {
            //adding code later
        }
        iterator begin(){
            return iterator(bottom);
        }

        iterator end(){
            return iterator(top);
        }
    };
}
#endif //ITERTOOLS_CFAR_A_COMPRESS_HPP
