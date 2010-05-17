#ifndef E4FLIB_H
#define E4FLIB_H

extern FILE *logfile_fd;

struct ext4_inode;
struct ext4_dir_entry_2;

#ifndef NDEBUG
#define E4F_DEBUG(format, ...)      fprintf(logfile_fd, "[%s:%d] " format "\n"  \
                                                      , __PRETTY_FUNCTION__     \
                                                      , __LINE__, ##__VA_ARGS__)
#else
#define E4F_DEBUG(format, ...)      do { } while(0)
#endif

int e4flib_lookup_path(const char *path, struct ext4_inode **ret_inode);
void e4flib_free_inode(struct ext4_inode *inode);
int e4flib_initialize(char *fs_file);
char *e4flib_get_printable_name(char *s, struct ext4_dir_entry_2 *entry);
struct ext4_dir_entry_2 **e4flib_get_dentries_inode(struct ext4_inode *inode, int *n_read);
int e4flib_logfile(const char *logfile);
uint8_t *e4flib_get_data_blocks_from_inode(struct ext4_inode *inode);

#endif