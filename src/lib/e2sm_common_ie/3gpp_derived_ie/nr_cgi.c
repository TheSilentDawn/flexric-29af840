#include <assert.h>
#include <stddef.h>

#include "nr_cgi.h"

bool eq_nr_cgi(nr_cgi_t const * m0, nr_cgi_t const * m1)
{
    assert(m0 != NULL);
    assert(m1 != NULL);

    if (eq_plmn(&m0->plmn_id, &m1->plmn_id) != true)
        return false;
        
    if (m0->nr_cell_id != m1->nr_cell_id)
        return false;

    return true;
}

nr_cgi_t cp_nr_cgi(const nr_cgi_t * src)
{
  assert(src != NULL);

  nr_cgi_t dst = {0};

  dst.plmn_id = cp_plmn(&src->plmn_id);

  dst.nr_cell_id = src->nr_cell_id;


  return dst;
}
