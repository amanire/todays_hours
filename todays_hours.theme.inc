<?php

/**
 * @file
 * Theme functions for Today's Hours module
 */

/**
 * Returns HTML for an open hours
 * 
 * @param $variables
 *   An associative array containing:
 *   - display: the display style for the block (default/highlight)
 *   - hours: An array containing open and close hours
 *   - more_url: the URL path for more information
 *
 * @ingroup themeable
 */
function theme_todays_hours($variables) {
  $open = $variables['hours']['open']['hour-min'];
  $open_ampm = $variables['hours']['open']['am-pm'];
  $close = $variables['hours']['close']['hour-min'];
  $close_ampm = $variables['hours']['close']['am-pm'];
  $more_url = $variables['hours']['more-url'];
  $time_details = theme_todays_hours_times($open, $open_ampm, $close, $close_ampm);
  $output = <<<HTML
<div class='todays-hours-times'>
  $time_details
</div>
<div><a href="$more_url">More hours<span aria-hidden="true" class="thickChevron">&raquo;</span></a></div>
HTML;
  return $output;
}

/**
 * Returns HTML for an open hours mobile block
 * 
 * @param $variables
 *   An associative array containing:
 *   - display: the display style for the block (default/highlight)
 *   - hours: An array containing open and close hours
 *   - more_url: the URL path for more information
 *
 * @ingroup themeable
 */
function theme_todays_hours_mobile($variables) {
  $open = $variables['hours']['open']['hour-min'];
  $open_ampm = $variables['hours']['open']['am-pm'];
  $close = $variables['hours']['close']['hour-min'];
  $close_ampm = $variables['hours']['close']['am-pm'];
  $more_url = $variables['hours']['more-url'];
  $time_details = theme_todays_hours_times($open, $open_ampm, $close, $close_ampm);

  $output = <<<HTML
<a href="$more_url"><div class='todays-hours-times'>
  $time_details
</div>
</a>
HTML;
  return $output;
}

/**
 * Added by KB, returns specific HTML for the time the library opens & closes, or whether it is 
 * closed all day
 * @param string
 */
function theme_todays_hours_times($open, $open_ampm, $close, $close_ampm){
  /*check if the library is closed*/
  if ((($open == "12:00") && ($close) == ("12:00"))||
    (($open == "00:00") && ($close) == ("00:00"))){
    $time_details = 
    "<span class='todays-hours-times-closed'>CLOSED</span>";
  }
  else {
    $time_details = "<span class='todays-hours-times-open'><span class='time-hour-min'>$open</span>$open_ampm</span> - <span class='todays-hours-times-close'><span class='time-hour-min'>$close</span>$close_ampm</span>";
  }
  return $time_details;
}