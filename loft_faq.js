// $Id$

/**
 * @file
 * The main javascript file for the loft_faq module
 *
 * @ingroup loft_faq
 * @{ 
 */

var loftFaq = loftFaq || {};

//loftFaq.someFunction = function() {
//  
//}

Drupal.behaviors.loftFaq = function (context) {
  if (Drupal.jsEnabled){
    /**
     * Add Scrolling Anchors
     */
    $(".loft-faq-toc a, a.loft-faq-top").click(function() {
      
      //how far from the screen top do you want the item to land after scrolling
      var distanceFromTop = 50;
      var speed = 500;
      
      //get the name of the anchor
      var anchor = $(this).attr('href').split('#');
      
      //get the y point of the element to scroll to
      var destination;
      if ($('div.loft-faq-category-wrapper.' + anchor[1]).length) {
        destination = $('div.loft-faq-category-wrapper.' + anchor[1]).offset().top;
      }
      else {
        destination = $('.loft-faq-toc').offset().top;
      }
      
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

/** @} */ //end of group loft_faq
