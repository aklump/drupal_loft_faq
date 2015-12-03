<?php
/**
 * @file
 * loft_faq_node.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function loft_faq_node_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'loft_faq';
  $view->description = 'All published FAQ nodes';
  $view->tag = 'loft_faq';
  $view->base_table = 'node';
  $view->human_name = 'FAQ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;

  /* Sort criterion: Content: Sort Order (field_sort) */
  $handler->display->display_options['sorts']['field_sort_value']['id'] = 'field_sort_value';
  $handler->display->display_options['sorts']['field_sort_value']['table'] = 'field_data_field_sort';
  $handler->display->display_options['sorts']['field_sort_value']['field'] = 'field_sort_value';
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'default';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_options']['argument'] = 'loft_faq';

  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Question Topic (field_group) */
  $handler->display->display_options['arguments']['field_group_value']['id'] = 'field_group_value';
  $handler->display->display_options['arguments']['field_group_value']['table'] = 'field_data_field_group';
  $handler->display->display_options['arguments']['field_group_value']['field'] = 'field_group_value';
  $handler->display->display_options['arguments']['field_group_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_group_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_group_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_group_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_group_value']['transform_dash'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Core', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  /* Display: FAQs */
  $handler = $view->new_display('block', 'FAQs', 'block_1');

  $export['loft_faq'] = $view;

  return $export;
}
