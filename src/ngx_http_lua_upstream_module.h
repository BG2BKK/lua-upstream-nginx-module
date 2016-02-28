#ifndef NGX_LUA_HTTP_MODULE
#define NGX_LUA_HTTP_MODULE

// the NGX_HTTP_UPSTREAM_CONSISTENT_HASH define is support consistent_hash 
#define NGX_HTTP_UPSTREAM_CONSISTENT_HASH  0
// the NGX_HTTP_UPSTREAM_LEAST_CONN define is support least_conn 
#define NGX_HTTP_UPSTREAM_LEAST_CONN       0


#if (NGX_HTTP_UPSTREAM_LEAST_CONN)

//Mark the variable from ngx_http_upstream_least_conn_module.c file 
extern ngx_module_t ngx_http_upstream_least_conn_module;

//Mark the struct from ngx_http_upstream_least_conn_module.c file 
typedef struct {
    ngx_uint_t                        *conns;
} ngx_http_upstream_least_conn_conf_t;

#endif


//Mark the follow structure from ngx_http_consistent_hash_module.c file,
//i'll submit a patch to add a header file for consistent_module 

# if (NGX_HTTP_UPSTREAM_CONSISTENT_HASH)

//Mark the variable from ngx_http_upstream_consistent_hash_module.c file 
extern ngx_module_t ngx_http_upstream_consistent_hash_module;
#define NGX_CHASH_VIRTUAL_NODE_NUMBER 160


typedef struct {
    time_t                                  timeout;
    ngx_int_t                               id;
    ngx_queue_t                             queue;
} ngx_http_upstream_chash_down_server_t;


typedef struct {
    u_char                                  down;
    uint32_t                                hash;
    ngx_uint_t                              index;
    ngx_uint_t                              rnindex;
    ngx_http_upstream_rr_peer_t            *peer;
} ngx_http_upstream_chash_server_t;


typedef struct {
    ngx_uint_t                              number;
    ngx_queue_t                             down_servers;
    ngx_array_t                            *values;
    ngx_array_t                            *lengths;
    ngx_segment_tree_t                     *tree;
    ngx_http_upstream_chash_server_t     ***real_node;
    ngx_http_upstream_chash_server_t       *servers;
    ngx_http_upstream_chash_down_server_t  *d_servers;
} ngx_http_upstream_chash_srv_conf_t;


typedef struct {
    uint32_t                                hash;

#if (NGX_HTTP_SSL)
    ngx_ssl_session_t                  *ssl_session;
#endif

    ngx_http_upstream_chash_server_t       *server;
    ngx_http_upstream_chash_srv_conf_t     *ucscf;
} ngx_http_upstream_chash_peer_data_t;

#endif

#endif
