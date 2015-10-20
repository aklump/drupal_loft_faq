/**
 * Smooth scroll to anchors
 *
 * Looks first for a dom with id of the href fragment of the link; then it looks
   for an dom element by name=fragment
 *
 * @param function callback
 *  onClick callback function receives two params jQuery objects: link, target
 * @param object options
 * - distance: int
 *   How far above the anchor in pixels shoudl we scroll to?
 * - speed: int
 *
 * @return $(this)
 *
 * @author Aaron Klump, In the Loft Studios, LLC
 * @see http://www.intheloftstudios.com
 * @see http://gist.github.com/3112374
 */
(function( $ ) {
  $.fn.scrollingAnchors = function(callback, options) {
    var settings = $.extend( {
      'distance' : 100,
      'speed' : 200
    }, options);

    $(this).each(function() {
      var $jumpLink = $(this);
      $jumpLink.click(function() {

        // Get the name of the anchor
        var anchor      = $jumpLink.attr('href').split('#');
        anchor          = anchor[1];
        var $target     = $('#' + anchor);
        var destination = null;

        // We don't need a top anchor for #top
        if (anchor === 'top') {
          destination = 0;
        }

        // Otherwise look for element with anchor as name attr
        else {
          if (!$target.length) {
            $target = $('a[name="' + anchor + '"]');
          }
          if ($target.offset()) {
            destination = $target.offset().top;
            destination -= settings.distance;
          }
        }

        if (destination !== null) {
          $("html:not(:animated),body:not(:animated)")
          .animate({
            scrollTop: destination
          }, {
            duration: settings.speed,
            easing: "swing"
          });

          if (callback) {
            callback($jumpLink, $target);
          }
        }

      });
    });
    return $(this);
  };
})( jQuery );
