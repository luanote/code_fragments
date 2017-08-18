#define SrsAutoFree(className, instance) \
impl__SrsAutoFree<className> _auto_free_##instance(&instance, false)
#define SrsAutoFreeA(className, instance) \
impl__SrsAutoFree<className> _auto_free_array_##instance(&instance, true)
template<class T>
class impl__SrsAutoFree
{
private:
    T** ptr;
    bool is_array;
public:
    /**
     * auto delete the ptr.
     */
    impl__SrsAutoFree(T** p, bool array) {
        ptr = p;
        is_array = array;
    }
    
    virtual ~impl__SrsAutoFree() {
        if (ptr == NULL || *ptr == NULL) {
            return;
        }
        
        if (is_array) {
            delete[] *ptr;
        } else {
            delete *ptr;
        }
        
        *ptr = NULL;
    }
};
