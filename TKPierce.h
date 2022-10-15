#pragma once

template <typename key, typename var_type, var_type var>
class TKPierce
{
    friend var_type seize(key)
    {
        return var;
    }
};

#define TKPIERCE_BREAKDOWN(KEY, CLASS, VAR_NAME, VAR_TYPE) \
    struct KEY {};\
    template class TKPierce< KEY, VAR_TYPE CLASS::*, & CLASS::VAR_NAME >;\
    VAR_TYPE CLASS::* seize( KEY )

#define TKPIERCE_BREAKDOWN_STATIC(KEY, CLASS, VAR_NAME, VAR_TYPE) \
    struct KEY {};\
    template class TKPierce< KEY, VAR_TYPE *, & CLASS::VAR_NAME >;\
    VAR_TYPE * seize( KEY )

#define TKPIERCE_BREAKDOWN_FUNC(KEY, CLASS, VAR_NAME, RETURN_TYPE, ...) \
    struct KEY {};\
    template class TKPierce< KEY, RETURN_TYPE (CLASS::*)( ##__VA_ARGS__ ), & CLASS::VAR_NAME >;\
    RETURN_TYPE (CLASS::* seize( KEY ) )( ##__VA_ARGS__ )

#define TKPIERCE_BREAKDOWN_FUNC_STATIC(KEY, CLASS, VAR_NAME, RETURN_TYPE, ...) \
    struct KEY {};\
    template class TKPierce< KEY, RETURN_TYPE (*)( ##__VA_ARGS__ ), & CLASS::VAR_NAME >;\
    RETURN_TYPE (* seize( KEY ) )( ##__VA_ARGS__ )

#define SEIZE(INSTANCE, KEY) ( INSTANCE.* seize( KEY() ) )
#define SEIZE_STATIC(KEY) ( * seize( KEY() ) )
