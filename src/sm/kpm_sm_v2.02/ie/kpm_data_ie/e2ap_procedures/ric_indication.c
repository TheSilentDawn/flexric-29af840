#include <assert.h>

#include "ric_indication.h"

void free_kpm_ind_data(kpm_ric_indication_t* ind) 
{
  assert(ind != NULL);
  
  switch (ind->kpm_ind_hdr.type)
  {
    case FORMAT_1_INDICATION_HEADER:
        free_kpm_ind_hdr_frm_1(&ind->kpm_ind_hdr.kpm_ric_ind_hdr_format_1);
        break;
  
    default:
        assert(false && "Unknown Indication Header Type");
  }

  
  switch (ind->kpm_ind_msg.type)
  {
    case FORMAT_1_INDICATION_MESSAGE:
        free_kpm_ind_msg_frm_1(&ind->kpm_ind_msg.frm_1);
        break;
    
    // case FORMAT_2_INDICATION_MESSAGE:
    //     free_kpm_ind_msg_frm_2(&ind->kpm_ind_msg.frm_2);  // to be added
    //     break;

    // case FORMAT_3_INDICATION_MESSAGE:
    //     free_kpm_ind_msg_frm_3(&ind->kpm_ind_msg.frm_3);  // to be added
    //     break;
    
    default:
        assert(false && "Unknown Indication Message Type");
  }

  
}

kpm_ric_indication_t cp_kpm_ind_data(kpm_ric_indication_t const* src) 
{

  assert(src != NULL);
  kpm_ric_indication_t ret = {0};
  
  ret.kpm_ind_hdr.type = src->kpm_ind_hdr.type;

  switch (ret.kpm_ind_hdr.type)
  {
    case FORMAT_1_INDICATION_HEADER:
        ret.kpm_ind_hdr.kpm_ric_ind_hdr_format_1 = cp_kpm_ind_hdr_frm_1(&src->kpm_ind_hdr.kpm_ric_ind_hdr_format_1);
        break;
  
    default:
        assert(false && "Unknown Indication Header Type");
  }

  ret.kpm_ind_msg.type = src->kpm_ind_msg.type;

  switch (ret.kpm_ind_msg.type)
  {
    case FORMAT_1_INDICATION_MESSAGE:
        ret.kpm_ind_msg.frm_1 = cp_kpm_ind_msg_frm_1(&src->kpm_ind_msg.frm_1);
        break;
    
    // case FORMAT_2_INDICATION_MESSAGE:
    //     ret.kpm_ind_msg.frm_2 = cp_kpm_ind_msg_frm_2(&src->kpm_ind_msg.frm_2);  // to be added
    //     break;

    // case FORMAT_3_INDICATION_MESSAGE:
    //     ret.kpm_ind_msg.frm_3 = cp_kpm_ind_msg_frm_3(&src->kpm_ind_msg.frm_3);  // to be added
    //     break;
    
    default:
        assert(false && "Unknown Indication Message Type");
  }

  return ret;
}


bool eq_kpm_ind_data(kpm_ric_indication_t const* ind0, kpm_ric_indication_t const* ind1)
{
    assert(ind0 != NULL);
    assert(ind1 != NULL);

    if (ind0 == ind1) return true;

    // Indication Header

    if (ind0->kpm_ind_hdr.type == ind1->kpm_ind_hdr.type)
    {
        switch (ind0->kpm_ind_hdr.type)
        {
        case FORMAT_1_INDICATION_HEADER:
            if (eq_kpm_ind_hdr_frm_1(&ind0->kpm_ind_hdr.kpm_ric_ind_hdr_format_1, &ind1->kpm_ind_hdr.kpm_ric_ind_hdr_format_1) != true)
                return false;
            break;
        
        default:
            assert(false && "Unknown Indication Header Type");
        }
    }
    else
        return false;


    // Indication Message

    if (ind0->kpm_ind_msg.type == ind1->kpm_ind_msg.type)
    {
        switch (ind0->kpm_ind_msg.type)
        {
        case FORMAT_1_INDICATION_MESSAGE:
            if (eq_kpm_ind_msg_frm_1(&ind0->kpm_ind_msg.frm_1, &ind1->kpm_ind_msg.frm_1) != true)
                return false;
            break;
        
        // case FORMAT_2_INDICATION_MESSAGE:
        //     if (eq_kpm_ind_msg_frm_2(&ind0->kpm_ind_msg.frm_2, &ind1->kpm_ind_msg.frm_2) != true)  // to be added
        //         return false;
        //     break;

        // case FORMAT_3_INDICATION_MESSAGE:
        //     if (eq_kpm_ind_msg_frm_3(&ind0->kpm_ind_msg.frm_3, &ind1->kpm_ind_msg.frm_3) != true)  // to be added
        //         return false;
        //     break;

        default:
            assert(false && "Unknown Indication Message Type");
        }
    }
    else
        return false;

    
    return true;
}