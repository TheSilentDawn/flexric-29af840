#include <assert.h>

#include "../../../util/conversions.h"
#include "../../../sm/kpm_sm_v2.02/ie/asn/asn_constant.h"
#include "../../../sm/kpm_sm_v2.02/ie/asn/UEID-GNB-CU-F1AP-ID-List.h"
#include "../../../sm/kpm_sm_v2.02/ie/asn/UEID-GNB-CU-CP-E1AP-ID-List.h"

#include "dec_gnb.h"
#include "dec_global_gnb_id.h"
#include "dec_global_ng_ran.h"

gnb_t dec_gNB_UE_asn(const UEID_GNB_t * gnb_asn)
{
    gnb_t gnb = {0};

    // AMF UE NGAP ID
    memcpy(&gnb.amf_ue_ngap_id, gnb_asn->amf_UE_NGAP_ID.buf, 8);


    // GUAMI

    PLMNID_TO_MCC_MNC(&gnb_asn->guami.pLMNIdentity, gnb.guami.plmn_id.mcc, gnb.guami.plmn_id.mnc, gnb.guami.plmn_id.mnc_digit_len);

    OCTET_STRING_TO_INT8(&gnb_asn->guami.aMFRegionID, gnb.guami.amf_region_id);

    OCTET_STRING_TO_INT16(&gnb_asn->guami.aMFSetID, gnb.guami.amf_set_id);

    OCTET_STRING_TO_INT8(&gnb_asn->guami.aMFPointer, gnb.guami.amf_ptr);


    // gNB-CU UE F1AP ID List
    // C-ifCUDUseparated 

    if (gnb_asn->gNB_CU_UE_F1AP_ID_List->list.count != 0)
    {
        assert(gnb_asn->gNB_CU_UE_F1AP_ID_List->list.count >= 1 && gnb_asn->gNB_CU_UE_F1AP_ID_List->list.count <= maxF1APid);
        gnb.gnb_cu_ue_f1ap_lst_len = gnb_asn->gNB_CU_UE_F1AP_ID_List->list.count;
        gnb.gnb_cu_ue_f1ap_lst = calloc(1, sizeof(*gnb.gnb_cu_ue_f1ap_lst));

        for (size_t i = 0; i < gnb.gnb_cu_ue_f1ap_lst_len; i++)
        {
            memcpy(&gnb.gnb_cu_ue_f1ap_lst[i], gnb_asn->gNB_CU_UE_F1AP_ID_List->list.array[i], 1);
        }
    }
    else
    {
        gnb.gnb_cu_ue_f1ap_lst_len = 0;
    }

    
    //gNB-CU-CP UE E1AP ID List
    //C-ifCPUPseparated 

    if (gnb_asn->gNB_CU_CP_UE_E1AP_ID_List->list.count != 0)
    {
        assert(gnb_asn->gNB_CU_CP_UE_E1AP_ID_List->list.count >= 1 && gnb_asn->gNB_CU_CP_UE_E1AP_ID_List->list.count <= maxE1APid);
        gnb.gnb_cu_cp_ue_e1ap_lst_len = gnb_asn->gNB_CU_CP_UE_E1AP_ID_List->list.count;
        gnb.gnb_cu_cp_ue_e1ap_lst = calloc(1, sizeof(*gnb.gnb_cu_cp_ue_e1ap_lst));

        for (size_t i = 0; i < gnb.gnb_cu_cp_ue_e1ap_lst_len; i++)
        {
            memcpy(&gnb.gnb_cu_cp_ue_e1ap_lst[i], gnb_asn->gNB_CU_CP_UE_E1AP_ID_List->list.array[i], 1);
        }
    }
    else
    {
        gnb.gnb_cu_cp_ue_e1ap_lst_len = 0;
    }


    // RAN UE ID
    // Optional
    if (gnb_asn->ran_UEID->buf != NULL)
    {
        gnb.ran_ue_id = calloc(1, sizeof(*gnb.ran_ue_id));
        memcpy(gnb.ran_ue_id, gnb_asn->ran_UEID->buf, 1);
    }
    


    //  M-NG-RAN node UE XnAP ID
    // C- ifDCSetup
    if (gnb_asn->m_NG_RAN_UE_XnAP_ID != NULL)
    {
        gnb.ng_ran_node_ue_xnap_id = calloc(1, sizeof(*gnb.ng_ran_node_ue_xnap_id));
        memcpy(gnb.ng_ran_node_ue_xnap_id, gnb_asn->m_NG_RAN_UE_XnAP_ID, 1);
    }
    

    // Global gNB ID
    // 6.2.3.3
    // Optional

    gnb.global_gnb_id = dec_global_gnb_id_asn(gnb_asn->globalGNB_ID);


    // Global NG-RAN Node ID
    // C-ifDCSetup

    gnb.global_ng_ran_node_id = dec_global_ng_ran_asn(gnb_asn->globalNG_RANNode_ID);


    return gnb;
}
