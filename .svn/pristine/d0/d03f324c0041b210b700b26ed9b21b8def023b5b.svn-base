<?php

include_once 'blade/view.ccauser.blade.inc';
include_once COMMON.'class.common.inc';
//include_once './common/class.common.cca.inc';

?>

<div class="panel panel-default">
<div class="panel-heading">Search Co-currricular Activities</div>
    	<div class="panel-body">

			<div id="form">
				<form action="#" method="post" class="form-horizontal">

					<div class="form-group">
           <label class="checkbox-inline"> <input type ="checkbox" name="catCheck" ></label>
						<label class="control-label col-sm-4" for="txtQuestion"> Catagory:   </label>

						<div class="col-sm-6">
						<?php $var='<select type="text" class="form-control" value=""  name="txtQuestionDDL" placeholder="Select Catagory Name......"/>';


							$Result = $_CCAUSERBAO->getCategories();
							//building the Category options
							if($Result->getIsSuccess())
							{

								$Category = $Result->getResultObject();

								//$var = $var.'<option value="select">Select</option>';
						       for ($i=0 ; $i < sizeof($Category); $i++)
						        {

						       		$cat = $Category[$i];

						$var = $var.'<option value="'.$cat->getCategoryName().'"';

						 $var=$var.'>'.$cat->getCategoryName(); '</option>';

						}
					}

						$var = $var.'</select>';
							echo $var;
						  ?>

</div>
					</div>
   <br>
   <br>

					<div class="form-group">
          <label class="  checkbox-inline"> <input type="checkbox" name="orgCheck"></label>
						<label class="control-label col-sm-4" for="Organizer"> Organizer:   </label>

						<div class="col-sm-6">
						<?php $var='<select type="text" class="form-control" value=""  name="Organizer" placeholder="Select Organizer Name......"/>';


							$Result = $_CCAUSERBAO->getOrganizers();
							//building the Category options
							if($Result->getIsSuccess())
							{

								$Organizer = $Result->getResultObject();

								//$var = $var.'<option value="select">Select</option>';

						       for ($i=0 ; $i < sizeof($Organizer); $i++)
						        {

						       		$org = $Organizer[$i];


						$var = $var.'<option value="'.$org->getOrganizerName().'"';

						$var=$var.'>'.$org->getOrganizerName(); '</option>';


						}
					}

						$var = $var.'</select>';
							echo $var;
						 ?>

						</div>
					</div>

          <br>
          <br>

					<div class="form-group">
            <label class="checkbox-inline"><input type="checkbox" name="dateCheck"></label>
						<label class="control-label col-sm-4" for="Date"> Date:   </label>
						<div class="col-sm-6">
						<input type="date" class="form-control"  name="Date" placeholder="Select Date......"/>

						</div>
					</div>

          <br>
          <br>

					<div class="form-group">

            <label class="checkbox-inline"><input type="checkbox" name="rangeCheck"></label>
						<label class="control-label col-sm-4" for="Date"> Enter The Range:</label>
						<div class="col-sm-6">

						<input  type="date" class="form-control"  name="Date1" placeholder="Select Initial Date......"/>
						<label>To</label>
						<input type="date" class="form-control"  name="Date2" placeholder="Select Final Date......"/>


						</div>
					</div>

          <br>
          <br>

					<div class="form-group">

    				<button style=" margin-left: 80px; width: 150px" type="submit" name="SearchEvent">Search Event</button>

				</div>
				</div>



			</div>

</form>
<?php

	if (isset($_POST['SearchEvent'])){
		//only catagory
		if (isset($_POST['catCheck']) && !isset($_POST['dateCheck']) && !isset($_POST['orgCheck'])){
				$value1 = $_POST['txtQuestionDDL'];
				$query = "select * from mytable where category = '$value1' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where category = '$value1' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) ASC, DAY(DATE) ASC";
        //echo $query;
        $Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
		//only organizer
		else if (isset($_POST['orgCheck']) && !isset($_POST['catCheck']) && !isset($_POST['dateCheck'])){
				$value2 = $_POST['Organizer'];
				$query = "select * from mytable where Organizer = '$value2' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where Organizer = '$value2' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) ASC, DAY(DATE) ASC";
        //echo $query;
        $Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//only date
		else if (isset($_POST['dateCheck'])&&!isset($_POST['orgCheck']) && !isset($_POST['catCheck'])){
				$value3 = $_POST['Date'];
				$query = "select * from mytable where date = '$value3' && date >= CURDATE() ";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where date = '$value3' && date < CURDATE() ";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//only catagory && organizer
		else if (isset($_POST['catCheck']) && isset($_POST['orgCheck'])&&!isset($_POST['dateCheck'])){
				$value2 = $_POST['Organizer'];
				$value1 = $_POST['txtQuestionDDL'];
				$query = "select * from mytable where category = '$value1' and Organizer = '$value2' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where category = '$value1' and Organizer = '$value2' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) DESC, DAY(DATE) ASC";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//catagory && date
			else if (isset($_POST['catCheck']) && !isset($_POST['orgCheck']) &&isset($_POST['dateCheck'])){
				$value3 = $_POST['Date'];
				$value1 = $_POST['txtQuestionDDL'];
				$query = "select * from mytable where category = '$value1' and date = '$value3' && date >= CURDATE() ";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where category = '$value1' and date = '$value3' && date < CURDATE() ";
        //echo $query;
        $Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//organizer && date
			else if (!isset($_POST['catCheck']) && isset($_POST['orgCheck'])&&isset($_POST['dateCheck'])){
				$value3 = $_POST['Date'];
				$value2 = $_POST['Organizer'];
				$query = "select * from mytable where Organizer = '$value2' and date = '$value3' && date >= CURDATE() ";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where Organizer = '$value2' and date = '$value3' && date < CURDATE() ";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//catagory && organizer && date
			else if (isset($_POST['catCheck']) && isset($_POST['orgCheck']) &&isset($_POST['dateCheck'])){
				$value3 = $_POST['Date'];
				$value1 = $_POST['txtQuestionDDL'];
				$value2 = $_POST['Organizer'];
				$query = "select * from mytable where category = '$value1' and date = '$value3' and Organizer='$value2' && date >= CURDATE()";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where category = '$value1' and date = '$value3' and Organizer='$value2' && date < CURDATE()";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}

			//only range
			else if (isset($_POST['rangeCheck'])&& !isset($_POST['orgCheck']) && !isset($_POST['catCheck']) && !isset($_POST['dateCheck'])){
				$valued1 = $_POST['Date1'];
				$valued2 = $_POST['Date2'];

				$query = "select * from mytable where  date between '$valued1' and'$valued2' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where  date between '$valued1' and'$valued2' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) DESC, DAY(DATE) ASC";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//catagory && drange
			else if (isset($_POST['catCheck']) && !isset($_POST['orgCheck']) && isset($_POST['rangeCheck']))
			{
				$valued1 = $_POST['Date1'];
				$valued2 = $_POST['Date2'];
					$value3 = $_POST['Date'];
				$value1 = $_POST['txtQuestionDDL'];
				$query = "select * from mytable where category = '$value1' and date between '$valued1' and '$valued2' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where category = '$value1' and date between '$valued1' and '$valued2' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			//catagory && drange
			else if (!isset($_POST['catCheck']) && isset($_POST['orgCheck']) && isset($_POST['rangeCheck']))
			{
				$valued1 = $_POST['Date1'];
				$valued2 = $_POST['Date2'];
					$value = $_POST['Organizer'];
				$value1 = $_POST['txtQuestionDDL'];
				$query = "select * from mytable where Organizer = '$value' and date between '$valued1' and '$valued2' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where Organizer = '$value' and date between '$valued1' and '$valued2' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}
			else if (isset($_POST['catCheck']) && isset($_POST['orgCheck']) &&isset($_POST['rangeCheck'])){
				$valued1 = $_POST['Date1'];
				$valued2 = $_POST['Date2'];
				$value1 = $_POST['txtQuestionDDL'];
				$value2 = $_POST['Organizer'];
				$query = "select * from mytable where category = '$value1' and Organizer='$value2' and date between '$valued1' and '$valued2' && date >= CURDATE() ORDER BY YEAR(Date) ASC, MONTH(Date) ASC, DAY(DATE) ASC";
				//echo $query;
				$Result = $_CCAUSERBAO->SearchEvent($query);

        $query1 = "select * from mytable where category = '$value1' and Organizer='$value2' and date between '$valued1' and '$valued2' && date < CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) ASC, DAY(DATE) ASC";
        //echo $query;
        $Result1 = $_CCAUSERBAO->SearchEvent1($query1);
			}

		}

?>

  
