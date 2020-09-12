#include <math.h>
#include "cvxconvexhull.h"
#include "cvxedgesorter.h"
#include "cvxutility.h"

static
CvxNode*
cvx_convex_find_least_angle (CvxConvexHull* convex, GList* work_list, 
                             CvxNode* node)
{
  CvxNode* result;
  double max_angle = 2 * M_PI; // maximum angle

  while (work_list != NULL)
  {
    CvxNode* target = (CvxNode*) work_list->data;
    double vec0_x = target->x - node->x;
    double vec0_y = target->y - node->y;
    double vec1_x = convex->x;
    double vec1_y = convex->y;
    double angle = cvx_utility_calc_angle (vec0_x, vec0_y, 
                                           vec1_x, vec1_y);
    if (angle < max_angle)
    {
      max_angle = angle;
      result = target;
    }
    work_list = g_list_next (work_list);
  }

  return result;
}

static
GList*
cvx_convex_hull_calc (CvxConvexHull* convex, GList* all_nodes)
{
  GList* work_list = g_list_copy (all_nodes);
  CvxNode* start_node = convex->start_node;
  CvxNode* node = start_node;
  CvxNode* next = NULL;
  GList* convex_nodes = NULL;

  convex->x = 1.0;
  convex->y = 0.0;

  while (next != start_node)
  {
    next = cvx_convex_find_least_angle (convex, work_list, node);
    convex_nodes = g_list_append (convex_nodes, next);
    work_list = g_list_remove (work_list, next);

    convex->x = next->x - node->x;
    convex->y = next->y - node->y;
    node = next;
  }

  g_list_free (work_list);

  return convex_nodes;
}

static
void
cvx_convex_hull_calc_start (GtkWidget*  button,
                            gpointer    user_data)
{
  CvxAlgorithm*  algorithm  = (CvxAlgorithm*) user_data;
  CvxConvexHull* convex     = (CvxConvexHull*) algorithm;
  CvxField*      field      = algorithm->field;
  CvxPolygon*    polygon    = field->polygon;
  GList*         all_nodes  = field->node_list->nodes;

  convex->start_node   = cvx_edge_sorter_find_right_end (all_nodes);
  convex->convex_nodes = cvx_convex_hull_calc (convex, all_nodes);
  cvx_polygon_set_shape (polygon, convex->convex_nodes);

  cvx_field_repaint (field);
}

static
void
cvx_convex_hull_build_controller (CvxAlgorithm* algorithm)
{
  GtkWidget* controller = gtk_hbox_new (FALSE, 0);
  GtkWidget* label = gtk_label_new (CVX_CONVEX_HULL_MESSAGE);
  GtkWidget* button = 
               gtk_button_new_with_label (CVX_CONVEX_HULL_BUTTON_LABEL);

  gtk_box_pack_start (GTK_BOX (controller), label, TRUE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (controller), button, FALSE, FALSE, 0);

  g_signal_connect (G_OBJECT (button), "clicked",
                    G_CALLBACK (cvx_convex_hull_calc_start), algorithm);

  algorithm->controller = controller;
}

CvxAlgorithm*
cvx_convex_hull_new (CvxField* field)
{
  CvxAlgorithm* retvar = cvx_algorithm_new (field, sizeof (CvxConvexHull));
  if (retvar == NULL) return NULL;

  cvx_convex_hull_build_controller (retvar);

  return retvar;
}

