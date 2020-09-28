$(document).ready(function(){
    $("#anim").mouseenter(function(){
      $("#elem").animate({
        opacity: '0.5',
        height: '150px',
        width: '150px'
      });
    });
  });

  $(document).ready(function(){
    $("#anim").mouseleave(function(){
      $("#elem").animate({
        opacity: '1',
        background: '#98bf21',
        height: '100',
        width: '100'
      });
    });
  });

  $(document).ready(function(){
    $("#create").click(function(){
      $("#elem").addClass("pos");
    });
  });

  $(document).ready(function(){
    $("#child").click(function(){
        $("#children").children().css({"height": "500"});
    });
  });
