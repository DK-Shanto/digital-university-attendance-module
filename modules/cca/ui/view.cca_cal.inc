<?php

include_once 'blade/view.cca_cal.blade.inc';
include_once 'blade/view.ccauser.blade.inc';
include_once COMMON.'class.common.inc';
//include_once './common/class.common.cca.inc';
include_once 'blade/view.cca.blade.inc';


if(!(isset($_GET['Show_CCA'])))
{
 ?>



 <div class="panel panel-default">

    <div class="panel-heading">Calender</div>

    <div class="panel-body">

<div>
  <script>
         function goLastMonth(month, year){
             if(month == 1){
                 --year;
                 month = 13;
             }
             document.location.href = "<?php $_SERVER['PHP_SELF'];?>
 ?month="+(month-1)+"&year="+year;
         }
         function goNextMonth(month, year){
             if(month == 12){
                 ++year;
                 month = 0;
             }
             document.location.href = "<?php $_SERVER['PHP_SELF'];?>
  ?month="+(month+1)+"&year="+year;
         }

     </script>

	        <table border='2'>
			       <tr>
				         <td><input style='width:50px;' type='button' value='<' name='previousbutton' onclick="goLastMonth(<?php echo $month.",".$year?>)"></td>
						 <td colspan='5'><?php echo $monthName.", ".$year;?></td>
						 <td><input style='width:50px;' type='button' value='>' name='nextbutton' onclick="goNextMonth(<?php echo $month.",".$year?>)"></td>
				   </tr>
				   <tr>
				         <td width='250px' height='50px'>Sun</td>
						 <td width='250px' height='50px'>Mon</td>
						 <td width='250px' height='50px'>Tue</td>
						 <td width='250px' height='50px'>Wed</td>
						 <td width='250px' height='50px'>Thu</td>
						 <td width='250px' height='50px'>Fri</td>
						 <td width='250px' height='50px' >Sat</td>
				   </tr>
				   <?php
				       echo "<tr>";
				       $day1=date("j");
					   for($i=1;$i<$numDays+1;$i++,$counter++)
					   {


					   	$timeStamp=strtotime("$year-$month-$i");

					   	$presentDate = date("Y-m-d",$timeStamp);
              $ccaName = "";


              	$Result = $_CCABAO->getAllCCA();

              	//if DAO access is successful to load all the users then show them one by one
              	if($Result->getIsSuccess()){

              		$CCAList = $Result->getResultObject();
}

					   	for($k=0; $k<sizeof($CCAList); $k++)
					   	{
					   		$cca = $CCAList[$k];
					   		if($cca->getDate () == $presentDate)
					   		{
					   			$ccaName.= ($cca->getCat().",");
					   		}

					   		if(strlen($ccaName)>21)
					   		{
					   			$ccaName .= "....";
					   			break;
					   		}

					   		$ccaName .= " ";

					   	}





						   if($i==1)
						   {
							  $firstDay=date("w",$timeStamp);
						       for($j=0;$j<$firstDay;$j++,$counter++)
							   {
							   echo "<td>&nbsp;</td>"; //blank space
							   }
						   }
						   if($counter %7==0)
						   {
							   echo "</tr><tr>";
						   }

						   if( $timeStamp == strtotime(date("Y-m-d")))
						   {


						   	?>

						   	<td width='250px' height='50px' align='center' bgcolor = "#F0F6FA">
						   	<a href="?Show_CCA=<?php echo $year."-".$month."-".$i; ?>" > <?php echo $i;?> </a>
						   	<br>
	         <?php echo $ccaName;?>
						   </td>



						<?php

						   }
						   else
						   {
						   	?>
						   	<td width='250px' height='50px' align='center' >
						   		<a href="?Show_CCA=<?php echo $year."-".$month."-".$i; ?>" > <?php echo $i ;?> </a>
						   		<br>
                  <?php echo $ccaName;?>
						   		</td>
						   <?php
						   }


					   }

					   echo "</tr>";
				   ?>
			</table>

</div>

<?php
}
elseif(isset($_GET['Show_CCA']))
{
	$currentDate = $_GET['Show_CCA'];

	$currentMonth = date("F", strtotime($currentDate));
	$currentYear = date("Y",strtotime($currentDate));
	$currentDay = date("d",strtotime($currentDate));



	$previousDate = date('Y-m-d', strtotime('-1 day', strtotime($currentDate)));
	$previousDateDay = date("d",strtotime($previousDate));
	$previousDateMonth = date("m",strtotime($previousDate));
	$previousDateYear = date("Y",strtotime($previousDate));

	//echo $previousDateDay;

	$nextDate = date('Y-m-d', strtotime('+1 day', strtotime($currentDate)));
	$nextDateDay = date("d",strtotime($nextDate));
	$nextDateMonth = date("m",strtotime($nextDate));
	$nextDateYear = date("Y",strtotime($nextDate));


  $query = "select * from mytable where date = '$currentDate'";
  //echo $query;
  $Result = $_CCAUSERBAO->SearchEvent($query);

?>




	<?php
}
	?>


	</div>
	</div>
