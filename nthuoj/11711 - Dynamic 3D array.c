unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k) {
  unsigned ***ppp, **pp, *p;
  ppp = (unsigned ***)malloc(n*sizeof(unsigned **) + n*m*sizeof(unsigned *) + n*m*k*sizeof(unsigned));
  pp = (unsigned **)(ppp + n);
  p = (unsigned *)(ppp + n + n*m);
  for(unsigned i = 0; i < n; i++) {
    ppp[i] = pp+m*i;
    for(unsigned j = 0; j < m; j++)
      ppp[i][j] = p + m*k*i + k*j;
  }
  return ppp;
}

void delete_3d_array(unsigned ***ppp){
  free(ppp);
}