<?php

/**
 * @file
 *  Administration callbacks for the module.
 */

/**
 * Configuration form for the domain redirect settings.
 */
function domain_temp_redirect_config_form($form, &$form_state) {
  $domains = domain_domains();
  $options = array();
  foreach ($domains as $domain) {
    $options[$domain['domain_id']] = $domain['sitename'];
  }

  $form['domain_temp_redirect_disabled_domains'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Temporary disabled domains'),
    '#default_value' => variable_get('domain_temp_redirect_disabled_domains', array()),
    '#description' => t('Select which domains should be temporary disabled for the people who do not have the <em>Access temporary disabled domains</em> permission. They will be redirected to the target domain.'),
  );
  $form['domain_temp_redirect_target_domain'] = array(
    '#type' => 'select',
    '#title' => t('Target domain'),
    '#default_value' => variable_get('domain_temp_redirect_target_domain', NULL),
    '#options' => $options,
  );
  return system_settings_form($form);
}
