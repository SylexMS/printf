#include "main.h"

/**
 * init_params - cleaes strcut field and rest buf
 *
 * @params: params struct
 * @ap: arg ptr
*/

void init_params(params_type *params, va_list ap)
{
	params->usnd = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UNIT_MAX;

	params->h_mod = 0;
	params->l.mod = 0;
	(void)ap;
}
