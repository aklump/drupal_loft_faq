//$Id: _module_slim.js 292 2010-09-17 20:47:05Z root $
// $Id$

/**
 * @file
 * The main javascript file for the loft_faq module
 *
 * @ingroup loft_faq
 * @{ 
 */

(function ($) {

Drupal.loftFaq = Drupal.loftFaq || {};
//Drupal.loftFaq.someVariable = Drupal.loftFaq.someVariable || {};

//Drupal.loftFaq.someFunction = function() {
//  
//}

/**
 * Core behavior for loft_faq.
 */
Drupal.behaviors.loftFaq = {
  attach: function (context, settings) {
    
    /**
     * Add Scrolling Anchors
     */
    $(".loft-faq-toc a").click(function() {
      
      //how far from the screen top do you want the item to land after scrolling
      var distanceFromTop = 50;
      var speed = 500;
      
      //get the name of the anchor
      var anchor = $(this).attr('href').split('#');
      
      //get the y point of the element to scroll to
      var destination = $('div.loft-faqs-wrapper.' + anchor[1]).offset().top;
      
      //do the scrolling
      $("html:not(:animated),body:not(:animated)")
      .animate(
        {
          scrollTop: destination - distanceFromTop
        },
        {
          duration: speed,
          easing: "swing"
        }
      );
      return false;
    });

	}
}

/**
 * @} End of "defgroup admin_behaviors".
 */
 
})(jQuery);

/** @} */ //end of group loft_faq
