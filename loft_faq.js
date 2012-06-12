/**
 * @file
 * The main javascript file for the loft_faq module
 *
 * @ingroup loft_faq
 * @{
 */

(function ($) {

  Drupal.loftFaq = Drupal.loftFaq || {};

  /**
   * Core behavior for loft_faq.
   */
  Drupal.behaviors.loftFaq = {
    attach: function (context, settings) {

      /**
       * Add Scrolling Anchors
       */
      $('dl.loft-faq-category')
      .once('loft-faq', function(){
        var $list = $(this);

        $list.find('dd.loft-faq-answer')
        .addClass('collapsed')
        .hide();
        $list.find('dt.loft-faq-question')
        .addClass('collapsed')
        .wrapInner('<a href="#">')
        .find('a')
        .click(function(){
          var $question = $(this).parent('dt');
          var $answer = $question.next('dd');
          if ($answer.find(':visible').length) {
            $answer.hide();
          }
          else {
            $answer.show();
          }
          $answer.toggleClass('collapsed')
          .toggleClass('showing');
          $question.toggleClass('collapsed')
          .toggleClass('showing');
          return false;
        });
      });

      $(".loft-faq-toc a, a.loft-faq-top").click(function() {

        //how far from the screen top do you want the item to land after scrolling
        var distanceFromTop = 50;
        var speed = 100;

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

})(jQuery);

/** @} */ //end of group loft_faq
