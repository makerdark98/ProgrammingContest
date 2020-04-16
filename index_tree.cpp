#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_SIZE 10000007
#define L_CHILD(i) ((i) << 1)
#define R_CHILD(i) (((i) << 1) + 1)
#define PARENT(i) ((i) >> 1)
using namespace std;

struct log_t {
  int data;
  int timestamp;
};

int base;
int index_tree[MAX_SIZE];
bool is_updated[MAX_SIZE];
log_t updated_log[MAX_SIZE];


void build(const vector<int>& data) {

  int size = data.size();
  for (base = 1; base < size; base <<= 1)
    ;

  for (int i = 0; i < size; i++) {
    index_tree[base + i] = data[i];
  }

  for (int level_base = base >> 1; level_base > 0; level_base >>= 1) {
    for (int i = 0; i < level_base; i ++) {
      index_tree [level_base + i] = max (index_tree[L_CHILD(level_base + i)], index_tree[R_CHILD(level_base + i)]);
    }
  }
}

void update(int idx, int data) {
  int real_idx = base + idx;
  index_tree[real_idx] = data;

  real_idx >>= 1;
  while (real_idx > 0) {
    index_tree[real_idx] = max (index_tree[L_CHILD(real_idx)], index_tree[R_CHILD(real_idx)]);
  }
}

void update_range_internal(int s, int e, int data) {
  static int timestamp = 2;
  while (s < e) {
    if (s % 2 == 1) {
      updated_log[s] = {data, timestamp};
      is_updated[s] = true;
      s ++;
    }
    if (e % 2 == 0) {
      updated_log[e] = {data, timestamp};
      is_updated[e] = true;
      e --;
    }

    s >>= 1;
    e >>= 1;
    if (s == e) updated_log[s] = {data, timestamp};
  }
  while (s > 0) {
    is_updated[s] = true;
    s >>= 1;
  }

  timestamp ++;
}

void update_range(int s, int e, int data) {
  update_range_internal(base + s, base + e, data);
}


int query_internal(int s, int e) {
  int retval = 0;
  while (s < e) {
    retval = s % 2 == 1 ? max(retval, index_tree[s++]) : retval;
    retval = e % 2 == 0 ? max(retval, index_tree[e--]) : retval;

    if (s == e) retval = max(retval, index_tree[s]);

    s >>= 1;
    e >>= 1;
  }

  return retval;
}
int query(int s, int e) {
  return query_internal(base + s, base + e);
}

int get_updated_value (int i) {
  int retval = index_tree[i];
  int current_time = 1;
  if (is_updated[L_CHILD(i)]) 

  return retval;
}
int query_lazy_internal(int s, int e) {
  int retval = 0;
  while (s < e) {
    retval = s % 2 == 1 ? max(retval, get_updated_value(s++)) : retval;
    retval = e % 2 == 0 ? max(retval, get_updated_value(e--)) : retval;

    s >>= 1;
    e >>= 1;

    if (s == e) {
      retval = max(retval, get_updated_value(s));
    }
  }
  return retval;
}
int query_lazy(int s, int e) {
  return query_lazy_internal(base + s, base + e);
}

int main () {
  vector<int> data = {1, 2, 5, 3, 7, 9, 4, 8, 2};
  build(data);
  update_range(0, 3, 10);
  printf("index_tree : ");
  for(int i=0;i < base << 1; i ++) {
    printf("%d ", index_tree[i]);
  }
  printf("\n");
  printf("updated_log : ");
  for(int i=0;i < base << 1; i ++) {
    if (updated_log[i].timestamp != 0) printf("%d : %d", i, updated_log[i].data);
  }
  printf("\n");
  printf("%d\n", query_lazy(0, 7));
  //printf("%d\n", query_lazy(0, 3));
}
