#ifndef DECODE_LABEL_INFO_FORMAT_1_KPM_V2_H
#define DECODE_LABEL_INFO_FORMAT_1_KPM_V2_H

#include "../../ie/asn/LabelInfoItem.h"
#include "../../ie/kpm_data_ie/data/label_info_lst.h"

label_info_lst_t kpm_dec_label_info_asn(const LabelInfoItem_t * label_info_asn);



#endif