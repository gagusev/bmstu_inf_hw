#define SWAP(type, a, b) ({ type tmp = a; a = b; b = tmp; })

#define SWAP_P(type, a, b) ({ type tmp = *a; *a = *b; *b = tmp; })