//      /adm/simul_efun/absolute_value.c
//      from the Nightmare mudlib
//      an absolute value simul_efun
//      created by Descartes 28 april 1993

int absolute_value(int x) {
    return ( (x>-1) ? x : -x);
}

int query_sign(int x) {
  if (!x) return 0;
  if (x > 0) return 1;
  if (x < 0) return -1;
}
