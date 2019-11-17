/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:18:37 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/16 18:19:07 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_object(t_cs *cs)
{
	printf("hash: %u\n", cs->hash);
	printf("zero: %u\n", cs->zero);
	printf("minus: %u\n", cs->minus);
	printf("space: %u\n", cs->space);
	printf("plus: %u\n", cs->plus);
	printf("minwid: %u\n", cs->minwid);
	printf("preci: %d\n", cs->preci);
	printf("len: %u\n", cs->len);
	printf("ext: %d\n", cs->ext);
	printf("type: %c\n", cs->type);
	printf("scape: %d\n", cs->scape);
	printf("other: %c\n", cs->other);
	printf("ptr: %s", cs->ptr);
	printf("-----------\n");
}


