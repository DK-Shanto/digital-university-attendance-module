<link rel="stylesheet" href="resources/css/fullcalendar.css" />
<script src="resources/css/jquery.min.js"></script>
<script src="resources/css/jquery-ui.min.js"></script>
<script src="resources/css/moment.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/fullcalendar/3.4.0/fullcalendar.min.js"></script>

<!-- Calendar Show -->
<script>   
/*showing the jason data sent from database*/
  $(document).ready(function() {
   /* $.ajax({
        url: './resources/t.php',
        type: 'POST',
        success: function(data){
            alert(data);
        },
        error: function(data){
            alert(data);
        }
    });*/

/*showing the events in calendar*/
   var calendar = $('#calendar').fullCalendar({
  /*  boolean. default: true,*/
    editable:true,
    navLinks: true,
    header:{
     left:'prev,next today',
     center:'title',
     right:'month,agendaWeek,agendaDay',

    },
    events:'./resources/t.php',
    selectable:true,
    selectHelper:true,
   });
  });
   
  </script>
 
  <br>
  
  <div class="container">
    <div id="calendar"></div>
  </div>
   
     