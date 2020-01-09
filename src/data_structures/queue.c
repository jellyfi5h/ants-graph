/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:20 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:46:49 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	init_queue(struct s_queue *queue, void *data)
{
	t_nodes	*room;

	queue->fifo = NULL;
	push(queue, data);
	room = data;
	room->v = 1;
	room->parent = NULL;
}

void	push(t_queue *queue, void *addr)
{
	t_links	*tmp;

	if (!queue->fifo)
	{
		queue->fifo = new_link(addr);
		queue->front = queue->fifo;
		queue->rear = queue->fifo;
	}
	else
	{
		tmp = queue->rear;
		tmp->next = new_link(addr);
		queue->rear = tmp->next;
	}
}

int		pop(t_queue *queue)
{
	t_links	*tmp;

	if (!queue->front)
		return (0);
	tmp = queue->front;
	queue->front = tmp->next;
	free(tmp);
	return (1);
}

void	free_queue(t_queue *queue)
{
	while (queue->front)
		pop(queue);
}

void	enqueue_neighbor(t_queue *queue, t_nodes *neighbor, t_nodes *parent)
{
	push(queue, neighbor);
	neighbor->parent = parent;
	neighbor->v = 1;
}
