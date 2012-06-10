<?php
// $Id$ 
//@@tags modules drupal 6.x
//@@details A basic skeleton for a module.admin.inc file

/** 
 * @file 
 * Administration page callbacks for the loft_faq module. 
 *
 * @ingroup loft_faq
 * @{
 */ 

/** 
 * Form builder. Configure my_module. 
 * 
 * @ingroup forms 
 * @see system_settings_form(). 
 */ 

function loft_faq_admin_settings() { 
  $form = array();
  
  $form['loft_faq_faq_page_nid'] = array(
    '#type' => 'textfield',
    '#description' => t("Create a page and then enter it's node id here.  The FAQs will be appended to that page."),
    '#title' => t('FAQ Page NID'),
    '#default_value' => variable_get('loft_faq_faq_page_nid', NULL),
    '#required' => TRUE,
    '#size' => 20,
  );
  
  $form['loft_faq_group_default'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Group for Questions'),
    '#default_value' => variable_get('loft_faq_group_default', LOFT_FAQ_GROUP_DEFAULT),
  );
 
  return system_settings_form($form); 
}

/** @} */ //end of group loft_faq
