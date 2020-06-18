//
// Created by nivtal9 & AVI HAIMOV on 13.6.2020.
//

namespace itertools{
    class range{
        int top, bottom ;
    public:
        ///start of iterator
        class iterator{
        private:
            int curr;
        public:
            iterator(int c){
                this->curr=c;
            }
            int operator *() {
                return curr;
            }
            const iterator operator ++(int) {
                iterator t = *(this);
                curr ++;
                return t;
            }
            iterator& operator ++() {
                curr ++;
                return *(this);
            }
            bool operator !=(const iterator& r) const {
                return this->curr != r.curr;
            }

            bool operator ==(const iterator& r) const {
                return this->curr == r.curr;
            }
        };///end of iterator
        typedef int	value_type;
        range(int t, int b){
            top=t;
            bottom=b;
        }
        iterator begin() {
            return iterator{top};
        }

        iterator end() {
            return iterator{bottom};
        }
    };
}