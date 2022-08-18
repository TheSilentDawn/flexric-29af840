#include "ngran_types.h"

#ifndef FLEXRIC_CONFIGURATION_FILE_H
#define FLEXRIC_CONFIGURATION_FILE_H 

#define FR_CONF_FILE_LEN 128

typedef struct {
  char conf_file[FR_CONF_FILE_LEN];
  char libs_dir[FR_CONF_FILE_LEN];
} fr_args_t;

fr_args_t init_fr_args(int argc, char* argv[]);

char* get_conf_ip(fr_args_t const*);

char* get_conf_e2port(fr_args_t const*);

char* get_conf_e42port(fr_args_t const*);

char* get_conf_db_dir(fr_args_t const*);

char* get_conf_db_name(fr_args_t const*);

char* get_conf_xappid(fr_args_t const*);

char* get_conf_e2nodes(fr_args_t const*);

char* get_conf_nbid(fr_args_t const*);

char* get_conf_mcc(fr_args_t const*);

char* get_conf_mnc(fr_args_t const*);

ngran_node_t get_conf_rantype(fr_args_t const*);

char* get_conf_cu_du_id(fr_args_t const*);
#endif

