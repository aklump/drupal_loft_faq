/**
 * @file
 * The main javascript file for the loft_faq module
 *
 * @ingroup loft_faq
 * @{
 */

(function ($) {

  Drupal.loftFaq = Drupal.loftFaq || {};

  Drupal.loftFaq.getIE = function ()
  // Returns the version of Windows Internet Explorer or a -1
  // (indicating the use of another browser).
  {
     var rv = -1; // Return value assumes failure.
     if (navigator.appName == 'Microsoft Internet Explorer')
     {
        var ua = navigator.userAgent;
        var re = new RegExp("MSIE ([0-9]{1,}[\.0-9]{0,})");
        if (re.exec(ua) !== null) {
         rv = parseFloat( RegExp.$1 );
        }
     }
     return rv;
  };

  /**
   * Core behavior for loft_faq.
   */
  Drupal.behaviors.loftFaq = {
    attach: function (context) {

      $('dl.loft-faq-category', context).once('loft-faq', function(){
        var $list = $(this);

        // Earlier versions of ie have a problem with the clicking?
        var ieVersion = Drupal.loftFaq.getIE();
        if (ieVersion == -1 || ieVersion > 8) {
          $list.find('dd.loft-faq-answer')
          .addClass('collapsed')
          .hide();
        }

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

      $("dl.loft-faq-category, .loft-faq-toc a, a.loft-faq-top").scrollingAnchors();

      Drupal.loftFaq.topLinks();
    }
  };

  Drupal.loftFaq.topLinks = function(context) {
    // Hide our return to top when the page is not long.
    var $links    = $('a.loft-faq-top', context);
    if ($("body").height() <= $(window).height()) {
      $links.hide();
    }
  };

})(jQuery);
