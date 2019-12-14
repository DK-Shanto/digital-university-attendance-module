<?php
include_once 'class.common.inc';

class Paginate
{
    public function __construct()
    {

    }

    public function paginationInitial(){

        $initial=null;

        if(isset($_GET['page'])){
            $initial=$_GET['page'];
        }
        else{
            $initial=0;
        }

        return $initial;
    }

    public function loadPaginatedData($Result){
        $ResultList=null;

        if(isset($_GET['page'])){
            $ResultList=$Result->getResultObject();
        }
        else{
            $ResultList=$Result->getResultObject();
        }

        return $ResultList;
    }

    public function paginate($results_per_page, $Page, $Result)
    {
        $paginate = null;
        $paginate .= '<div class="col-md-12">';
        $paginate .= '<ul class="pagination">';

        //Previous Button
        $paginate .= '<li class="page-item">';
        $paginate .= '<a class="page-link" href="';
        if (isset($_GET['page'])) {
            $result = $_GET['page'] - $results_per_page;
            if ($_GET['page'] == 0) {
                $paginate.='#';
            }else{
            $paginate .= $Page . '?page='.$result;
            }
        }else{
            $paginate.='#';
        }
        $paginate .= '" aria-label="Previous">';
        $paginate .= '<span aria-hidden="true">&laquo;</span>';
        $paginate .= '<span class="sr-only">Previous</span>';
        $paginate .= '</a>';
        $paginate .= '</li>';


        //Page Buttons
        if (!isset($_GET['page'])) {
            $page = 1;
        } else {
            $page = $_GET['page'];
        }

        $ResultNum = count($Result->getResultObject());
        $number_of_pages = ceil($ResultNum / $results_per_page);
        for ($i = 0; $i < $number_of_pages; $i++) {
            $pg=null;
            if (isset($_GET['page'])) {
                if ($_GET['page'] == $i * $results_per_page) {
                    $paginate .= '<li class="page-item active">';
                    $pg='#';
                } else {
                    $paginate .= '<li class="page-item">';
                    $pg=$Page.'?page='.$i*$results_per_page;
                }
            } else {
                if ($i == 0) {
                    $paginate.='<li class="page-item active">';
                    $pg='#';
                } else {
                    $paginate.='<li class="page-item">';
                    $pg=$Page.'?page='.$i*$results_per_page;
                }
            }
            $paginate.='<a class="page-link" href="';
            $paginate.=$pg;
            $paginate.='">';
            $paginate.=$i+1;
            $paginate.='</a>';
            $paginate.='</li>';

            $page++;
        }

        // Next Button

        $paginate.='<li class="page-item">';
        $paginate.='<a class="page-link" href="';

        if(isset($_GET['page'])){
            $result=$_GET['page']+$results_per_page;
            if ($_GET['page']>=$ResultNum-$results_per_page){
                $paginate.='#';
            }else{
            $paginate.=$Page.'?page='.$result;
            }
        }else{
            if($ResultNum>$results_per_page){
                $paginate.=$Page.'?page='.$results_per_page;
            }else{
                $paginate.='#';
            }

        }
        $paginate.='" aria-label="Next">';
        $paginate.=' <span aria-hidden="true">&raquo;</span>';
        $paginate.='<span class="sr-only">Next</span>';
        $paginate.='</a>';
        $paginate.='</li>';
        $paginate.='</ul>';
        $paginate.='</div>';

        return $paginate;
    }
}
?>